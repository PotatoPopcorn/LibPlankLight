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

#include <cstdio>
#include <cstdlib>

#include "../src/pluniverse.h"

#include "testhelper.h"

int main(int argc, char **argv)
{
    TestHelper th;
    if(!th.connectDevice(argc, argv))
    {
        exit(1);
    }
    PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
    uni->whiteout();
    th.sendDMX(uni);
    th.disconnectDevice();
    return 0;
}
