#ifndef UTILS_H_
#define UTILS_H_

void split_path(const std::string &path, std::string &dir, std::string &file) {
    size_t found = path.find_last_of("/");
    if (found == std::string::npos) {
        dir = ".";
        file = path;
    } else {
        dir = path.substr(0, found);
        file = path.substr(found + 1);
    }
}

std::string join_path(const std::string &dir, const std::string &subdir) {
    return dir + "/" + subdir;
}

#endif
