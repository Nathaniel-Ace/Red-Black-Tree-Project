#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include <string>
#include <vector>

std::string read_file(const std::string& file_path);
void write_file(const std::string& file_path, const std::vector<std::string>& words);

#endif // FILE_IO_HPP
