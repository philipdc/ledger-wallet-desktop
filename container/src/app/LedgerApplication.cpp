/*
 *
 * LedgerApplication
 * ledger-wallet-desktop
 *
 * Created by Pierre Pollastri on 23/02/2017.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#include "LedgerApplication.hpp"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_window.h"
#include "include/wrapper/cef_helpers.h"

LedgerApplication::LedgerApplication(QApplication &application, CefMainArgs &args)
        : _application(application), _args(args) {
    _cefRunLoop = new LedgerCefRunLoop(nullptr);
}

CefRefPtr<CefBrowserProcessHandler> LedgerApplication::GetBrowserProcessHandler() {
    return this;
}

void LedgerApplication::OnContextInitialized() {
    CEF_REQUIRE_UI_THREAD();
    _window.show();
    customizeWindow();

    CefBrowserSettings settings;
    CefWindowInfo info;

#if defined(OS_MACOSX)
    info.SetAsChild((NSView *)_window.winId(), 0, 0, _window.size().width(), _window.size().height());
#elif defined(OS_WIN)
    info.SetAsPopup(NULL, "Ledger Wallet");
#else

#endif
    CefBrowserHost::CreateBrowser(info, LedgerCefHandler::getInstance(), "https://google.fr", settings,
                                  NULL);
}


int LedgerApplication::run() {
    CefSettings settings;
    CefInitialize(_args, settings, this, NULL);
    _cefRunLoop->start();
    int ret = _application.exec();
    _cefRunLoop->stop();
    return ret;
}

LedgerApplication::~LedgerApplication() {
    delete _cefRunLoop;
}
