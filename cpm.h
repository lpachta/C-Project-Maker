#ifndef NPM_H
#define NPM_H


#include <map>
#include <string>
#include <vector>
using namespace std;

enum e_pars{
  NAME, PROJECT_PATH, KACER_DONALD, LANG_EXT, ZIP_PATH, AUTHOR, AUTHOR_STRING
};

typedef struct{
  string name;
}Tfile;

typedef struct{
  string arg;
  bool is_used;
  string val;
}Tpars;

class Cpm{
  private:
    map<string, bool> args{
      {"-h", false}, // Help
      {"-n", false}, // New Blank Project
      {"-m", false}, // Makefile
      {"-r", false}, // Rename a Project
      {"-z", false}, // New Project From zip
      {"-N", false}, // New Project From zip
      {"-L", false}, // New Project From zip
      {"-A", false} // New Project From zip
    };


    
    map<int, string> pars{
      {NAME, "NULL"},
      {PROJECT_PATH, "NULL"},
      {KACER_DONALD, "NULL"},
      {LANG_EXT, "NULL"},
      {ZIP_PATH, "NULL"},
      {AUTHOR, "NULL"},
      {AUTHOR_STRING, "NULL"}
    };

    vector<Tfile> files;

  public:
    void projectFromZip();
    bool replace(std::string& str, const std::string& from, const std::string& to);
    void renameFiles();
    void wrapMakeDir();
    void copyFiles();
    void makeDir(string dir);

    void renameProject();

    void wrapCreateMakefile();
    void loadOptions(int argc, char *argv[]);

    void loadFiles(int path);

    void makeProjectPath();
    void inputPar(int par);

    string getPar(int par){return pars[par];}
    bool getArg(string arg){return args[arg];}

    void setPar(int par, string val){pars[par] = val;}

    void setFile_name(int i, string par){files[i].name = par;}

    void addFile(Tfile file){files.push_back(file);}
    void addFiles(vector<Tfile> fileVec){
      for(Tfile file : fileVec){
        files.push_back(file);
      }
    }

    void createMakefile();

    string getName(int argc, char *argv[]);
};

#endif // !NPM_H
