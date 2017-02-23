/*
 *
 * LedgerCefHandler
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
#ifndef LEDGER_WALLET_DESKTOP_LEDGERCEFHANDLER_HPP
#define LEDGER_WALLET_DESKTOP_LEDGERCEFHANDLER_HPP

#include "include/cef_client.h"

#include <list>

class LedgerCefHandler : public CefClient,
                         public CefDisplayHandler,
                         public CefLifeSpanHandler,
                         public CefLoadHandler  {
public:
    static CefRefPtr<LedgerCefHandler> getInstance();

private:
    static CefRefPtr<LedgerCefHandler> _instance;
    IMPLEMENT_REFCOUNTING(LedgerCefHandler);
};


#endif //LEDGER_WALLET_DESKTOP_LEDGERCEFHANDLER_HPP
