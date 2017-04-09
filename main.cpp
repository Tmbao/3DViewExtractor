#include "camera_position.h"
#include "off_helpers.h"
#include "utils.h"
#include "view_extractor.h"
#include "view_provider_example.h"


int main(int argc, char const *argv[])
{
    if (argc == 2) {
        auto mesh = load_off(argv[1]);
        std::string prefix, _;
        split_path(argv[1], prefix, _);
        extract_view(mesh, new ViewProviderExample(), prefix);
        return 0;
    } else {
        cerr << "Invalid argument" << endl;
        return 1;
    }
}
