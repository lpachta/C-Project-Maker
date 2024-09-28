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
    void templateProject();

    /** @brief Napíše do terminálu jak otevřít README.md */
    void help();

    /** @brief Vytvoří novou složku s názvem, který zadá uživatel */
    void userMakeDir();
    
    /** @brief Napíše zprávu a pak nechá uživatele zadat název složky. Pokud neexistuje, proces se opakuje 
     * @param message Zpráva, kterou vypíše vždy před user inputem.
     * @param line Má být čtení pomocí getline()? 
     */
    string inputDir(string message, bool line);
    
    /** @brief Napíše zprávu a pak nechá uživatele zadat string.
     * @param message Zpráva, kterou vypíše vždy před user inputem.
     * @param line Má být čtení pomocí getline()?
     */
    string inputString(string message, bool line);
    
    /** @brief Smaže obsah pole files[] */
    void unloadFiles();
    
    /** @brief Přejmenuje složku, přejmenuje obsah složky, vytvří Makefile */
    void projectFromZipDir();
    
    /** @brief Nahradí substring substringem */
    bool replace(std::string& str, const std::string& from, const std::string& to);
    
    /** @brief Vyhledej a hahraď v názvech souborů */
    void renameFiles();
    
    /** @brief Zkopíruje soubory z jedné složky do druhé */
    void copyFiles();
    
    /** @brief Vytvoří složku */
    void makeDir(string dir);
    
    /** @brief Vytvoří Makefile */
    void wrapCreateMakefile();
    
    /** @brief Vyhodnotí, jaký argument byl zavolán a zavolá související funkci */
    void loadOptions(int argc, char *argv[]);
    
    /** @brief Načte názvy souborů do files[] */
    void loadFiles(int path);
    
    /** @brief Vytvoří pars[PROJECT_PATH] */
    void makeProjectPath();
    
    /** @brief Vytvoří pars[ZIP_PATH] */
    void makeZipDirPath();
    
    /** @brief Načte paramer
     * @param par index parametru v pars[]
     * */
    void inputPar(int par);
    
    /** @brief Srdce wrapCreateMakefile() */
    void createMakefile();
    
};

#endif // !NPM_H
