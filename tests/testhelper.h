// Copyright (C) 2019 by PotatoPopcorn (Tony Kerr)
//

// NOTE: Only the tests are subject to the following licence, The main source
// code is licenced under the GNU LGPL, plese see the README for more
// information

// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#ifndef TESTS_TESTHELPER_H
#define TESTS_TESTHELPER_H

#include <cstdio>
#include <cstring>

#include <string>

#include "../src/pldeviceartnet.h"
#include "../src/pldeviceenttecpro.h"
#include "../src/pluniverse.h"

class TestHelper
{
public:
    bool connectDevice(int argc, char **argv);
    bool disconnectDevice();

    bool sendDMX(PlanktonLighting::PLUniverse *universe);

private:
    std::string deviceMode;
    PlanktonLighting::PLDeviceEnttecPro *enttecProDevice;
    PlanktonLighting::PLDeviceArtnet *artnetDevice;
};

#endif //TESTS_TESTHELPER_H
