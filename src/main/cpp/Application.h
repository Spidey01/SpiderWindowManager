#ifndef Spider_src_main_cpp_Application_h
#define Spider_src_main_cpp_Application_h

#include <string>
#include <vector>
#include <ostream>

namespace Spider {
    class Application {
      public:
        Application(int argc, char* argv[]);
        int run();
        int main();

      private:
	void usage(std::ostream& to);

        typedef std::vector<std::string> OptionsList;
        OptionsList mOptionsList;

        const std::string mAppName;
    };
}

#endif // !Spider_src_main_cpp_version_h

