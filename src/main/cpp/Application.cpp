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

#include <iostream>
#include <cstdlib>


namespace Spider {

    Application::Application(int argc, char* argv[])
    {
        std::cout << "Application::Application(): called." << std::endl;
    }


    int
    Application::run()
    {
        std::cout << "Application::run(): called." << std::endl;
        return EXIT_SUCCESS;
    }

} // !Spider
