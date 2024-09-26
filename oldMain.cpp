#include <cstdio>
#include <cstdlib>
#include <ctime>
//#include <filesystem>
//#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "cpm.h"

//namespace fs = std::filesystem;
using namespace std;

/*
void makeDir(string dirPath){
  if(!fs::exists(dirPath)){
    fs::create_directory(dirPath);
    cout << "Vytvářím složku " + dirPath << endl;
  } else {
    cout << "Složka již exituje.\n";
  }
}

void makeMakeFile(string projectDir, string name, string autor, vector<string> sourceFiles, string CC){
  string makefileDir = projectDir + "Makefile";
  ofstream makefile(makefileDir);
  makefile << "# Projekt: " << name << endl;
  makefile << "# Autor: " << autor << endl;
  // DODĚLAT DATUM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  makefile << endl;

  makefile << "# VARS\nNAME=" << name << "\nSOURCE_FILES=";
  for(string file : sourceFiles){
    makefile << file << " ";
  }
  makefile << "\nCC=" << CC << "\n\nCFLAGS=-std=c99 -pedantic -Wall -g";

  makefile << "\nEXE_FILE=$(NAME)\nALL_FILES=.*"
              "\n\ncompile:\n	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(EXE_FILE)"
              "\n\nrun:\n	./$(EXE_FILE)\n\n\nclear-exe:\n	rm $(EXE_FILE)\n\nclear-bin:\n	rm -rf bin/ \n	rm -rf obj/"
              "\n\nclear-pack:\n	rm $(NAME).tar.gz\n	rm $(NAME).zip"
              "\n\npack: clear-bin\n	tar cvzf $(NAME).tar.gz $(ALL_FILES)\n	zip $(NAME).zip $(ALL_FILES)"
              "\n\nclear: clear-bin clear-pack clear-exe";
    

}

void copyFiles(string zipDirPath, vector<string> filesInZipDir, string projectPath){
  string copyTemp;
  string copyDestination;
  for (const auto & entry : fs::directory_iterator(zipDirPath)){
    filesInZipDir.push_back(fs::path(entry).filename());
    copyTemp = fs::path(entry).filename();
    //cout << copyTemp << endl;
    copyDestination = projectPath + copyTemp;
    //cout << copyDestination << endl << endl;
    fs::copy_file(entry.path(), copyDestination);
    cout << "Kopíruji soubor " << fs::path(entry).filename() << endl;
  }
}
*/

int main (int argc, char *argv[]) {

  if(argv[1] == (string)"-h" || argv[1] == (string)"help"){
    cout << "cpm project_name\n";
    return 0;
  }
  Cpm cpm;

  string name = cpm.getName(argc, argv);
  string projectPath = "./" + name + "/";

  string sourceExtentions = ".c";
  vector<string> sourceFiles = {"main.c", "pole.c"};
  string author = "Lukáš Pachta";






  cpm.createMakefile(name, projectPath, sourceExtentions, sourceFiles, author);
  return 0;
}

/*
int main (int argc, char *argv[]) {


  const string autor = "Lukáš Pachta";

  // Deklarace proměnných
  string name, zipDirPath, sourceFileExtention;

  // Přiřazení proměnných
  switch (argc) {

    case 1:
      cout << "Zadejte název nového projektu: ";
      cin >> name;

      cout << "Zadejte název složky extrahovaného archivu: ";
      cin >> zipDirPath;


    case 2:
      name = argv[1];

      cout << "Zadejte název složky extrahovaného archivu: ";
      cin >> zipDirPath;


    case 3:
      name = argv[1];

      zipDirPath = argv[2];

  }

  cout << "Zadejte typ souboru (bez tečky):";
  cin >> sourceFileExtention;

  // Dir
  string projectPath = "./" + name + "/";

  // Vector with filenames in zip directory
  vector<string> filesInZipDir;
  string copyDestination;


  string CC;
  if(sourceFileExtention == "cpp"){
    CC = "g++";
  } else if(sourceFileExtention == "c"){
    CC = "gcc";
  }

  vector<string> sourceFiles;
  cout << sourceFileExtention << endl;

  sourceFileExtention = "." + sourceFileExtention;
  cout << sourceFileExtention << endl;


  makeDir(projectPath);

  copyFiles(zipDirPath, filesInZipDir, projectPath);

  for(string fileInZipDir: filesInZipDir){
    if((fileInZipDir.find(sourceFileExtention) != string::npos) && !(fileInZipDir.find(".cbp") != string::npos)){
      sourceFiles.push_back(fileInZipDir);
      cout << fileInZipDir << endl;
    }
  }

  makeMakeFile(projectPath, name, autor, sourceFiles, CC);

  return 0;
}
*/
