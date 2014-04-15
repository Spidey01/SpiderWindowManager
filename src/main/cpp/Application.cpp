/**-
 * Copyright 2014-current Terry M. Poulin <BigBoss1964@gmail.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Application.h"
#include "version.h"

#include <cstdlib>
#include <cstring>
#include <iostream>


namespace Spider {

    static char *basename(char *path)
    {
        char *p = std::strrchr(path, '/');
        ++p;
        return p;
    }


    Application::Application(int argc, char* argv[])
        : mAppName(basename(argv[0]))
    {
        std::cout << "Application::Application(): called." << std::endl;

        std::cout << "mAppName => " << mAppName << std::endl;
        std::cout << "mOptionsList from: " << std::endl;
        for (int i=1; i < argc; ++i) {
            std::cout << "argv["<<i<<"] => " << argv[i] << std::endl;
            mOptionsList.push_back(argv[i]);
        }
    }


    int
    Application::run()
    {
        std::cout << "Application::run(): called." << std::endl;

        try {
            return main();
        } catch(std::exception& ex) {
            std::clog << ex.what() << std::endl;
            return EXIT_FAILURE;
        }
    }


    int
    Application::main()
    {
        std::cout << "Application::main(): called." << std::endl;

        for (OptionsList::const_iterator it = mOptionsList.begin(); it != mOptionsList.end(); ++it) {
            // std::string option = *it;
            // std::cout << "option => " << opt << std::endl;

            std::cout << "option => " << *it << std::endl;
            if (*it == "-h" || *it == "-help" || *it == "--help") {
                usage(std::cerr);
                return EXIT_SUCCESS;
            }
            else if (*it == "-v" || *it == "--version") {
                 std::cout << "Spider WM version " << SPIDER_VERSION << std::endl;
                return EXIT_SUCCESS;
            }
            else {
                std::cerr << mAppName << "unrecognized option: '" << *it << "'" << std::endl
                          << "try `" << mAppName << " --help`' for more information."
                          << std::endl;
                // common value of EX_USAGE from sysexits.h.
                return 64;
            }
        }
        return EXIT_SUCCESS;
    }


    void
    Application::usage(std::ostream& to)
    {
        to << "usage: " << mAppName << " [OPTION]..."
           << std::endl
           << "    -h     display this help and exit."
           << std::endl
           << "    -v     output version information and exit"
           << std::endl
           ;
    }

} // !Spider
