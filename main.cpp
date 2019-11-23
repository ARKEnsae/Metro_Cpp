#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include <boost/filesystem.hpp>

struct path_leaf_string
{
    std::string operator()(const boost::filesystem::directory_entry& entry) const
    {
        return entry.path().leaf().string();
    }
};

void read_directory(const std::string& name, stringvec& v)
{
    boost::filesystem::path p(name);
    boost::filesystem::directory_iterator start(p);
    boost::filesystem::directory_iterator end;
    std::transform(start, end, std::back_inserter(v), path_leaf_string());
}


int main()
{
    vector<string> v1,v2;
    read_directory(".", v1);
    cout << v1.size();
    for (int i = 0; i < v1.size(); i++) {
		std::cout << v1.at(i) << ' ';
	}
    return 0;
}
