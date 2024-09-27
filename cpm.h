#ifndef NPM_H
#define NPM_H

#include <map>
#include <string>
#include <vector>
using namespace std;

enum e_pars{
  NAME, PROJECT_PATH, KACER_DONALD, LANG_EXT, ZIP_PATH, AUTHOR, AUTHOR_STRING, ZIP_NAME
};

typedef struct{
  string name;
}Tfile;

class Cpm{
  private:
    map<int, string> pars{
      {NAME, "NULL"},
      {PROJECT_PATH, "NULL"},
      {KACER_DONALD, "NULL"},
      {LANG_EXT, "NULL"},
      {ZIP_PATH, "NULL"},
      {ZIP_NAME, "NULL"},
      {AUTHOR, "NULL"},
      {AUTHOR_STRING, "NULL"}
    };

    vector<Tfile> files;

  public:
    void help();
    void userMakeDir();
    string inputDir(string message, bool line);
    string inputString(string message, bool line);
    void unloadFiles();
    void projectFromZipDir();
    bool replace(std::string& str, const std::string& from, const std::string& to);
    void renameFiles();
    void wrapMakeDir();
    void copyFiles();
    void makeDir(string dir);
    void wrapCreateMakefile();
    void loadOptions(int argc, char *argv[]);
    void loadFiles(int path);
    void makeProjectPath();
    void makeZipDirPath();
    void inputPar(int par);
    void createMakefile();

    void addFiles(vector<Tfile> fileVec){
      for(Tfile file : fileVec){
        files.push_back(file);
      }
    }
};

#endif // !NPM_H
