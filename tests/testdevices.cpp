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
#include <string>
#include <vector>

#include "../src/pldevices.h"

int main(int argc, char **argv)
{
    PlanktonLighting::PLDevices devices;
    std::vector<std::string> types = devices.getSupportedTypes();
    printf("There is %lu types supported: \n", types.size());
    for(int i = 0; i < types.size(); ++i)
    {
        printf(" + %s\n", types[i].c_str());
    }

    std::vector<std::string> ava = devices.getAvailableDevices();
    printf("There is %lu devices avaliable: \n", ava.size());
    for(int i = 0; i < ava.size(); ++i)
    {
        printf(" + %s\n", ava[i].c_str());
    }
    return 0;
}
