#include <iostream>
#include "Directory.h"
#include "MarkDownEditor.h"

Directory getFileDirectory();

int main() {
	Directory directory(getFileDirectory());
	MarkDownEditor markDownEditor(directory.getDirectory());
	return 0;
}

Directory getFileDirectory() {
	Directory * directory = new Directory;
	while (!directory->isValid()) {
		std::cerr << "Invalid path.\n";
		delete directory;
		directory = new Directory;
	}
	return *directory;
}