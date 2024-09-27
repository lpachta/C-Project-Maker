#include "cpm.h"
#include <climits>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

void Cpm::help(){
  cout << "\n\nvi README.md\n\n\n";
}

void Cpm::loadOptions(int argc, char *argv[]){
  string arg;
  if(argc > 1){
    arg = argv[1];
  } else {
    cout << "Možné parametry: \n"; // Pak pridat ostatni args
    cout << "  -h // Help\n";
    cout << "  -z // Vytvoř projekt ze zip složky. Přejmenuje složku, přejmenuje soubory a vytvoří Makefile\n";
    cout << "  -d // Vytvoř novou složku.\n";
    cout << "  -c // Zkopíruj soubory ze složky do jiné (Pokud složka neexistuje, vytvoří ji.)\n";
    cout << "  -r // Přejmenuj soubory pomocí vyhledej a nahraď.)\n";
    cout << "  -m // Vytvoř Makefile\n";
    cout << endl;
  }

  if(arg == "-h"){help();}
  else if(arg == "-m"){wrapCreateMakefile();}
  else if(arg == "-c"){copyFiles();}
  else if(arg == "-r"){renameFiles();}
  else if(arg == "-z"){projectFromZipDir();}
  else if(arg == "-d"){projectFromZipDir();}
  else {
    return;
  }
}

void Cpm::userMakeDir(){
  if (pars[NAME] == "NULL"){
    pars[NAME] = inputString("Zadejte název složky, kterou chcete vytvořit", false);
  }
  makeDir(pars[NAME]);
}

void Cpm::projectFromZipDir(){
  if (pars[ZIP_NAME] == "NULL"){
    pars[ZIP_NAME] = inputDir("Zadejte název složky, kterou chcete přejmenovat: ", false);
  }
  makeZipDirPath();

  if(pars[NAME] == "NULL"){
    pars[NAME] = inputString("Zadejte nový název složky: ", false);
  }
  makeProjectPath();
  
  
  makeDir(pars[PROJECT_PATH]);
  copyFiles();
  renameFiles();

  fs::remove_all(pars[ZIP_PATH]);
  wrapCreateMakefile();
}


bool Cpm::replace(std::string& str, const std::string& from, const std::string& to){
  size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
      return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void Cpm::renameFiles(){
  if(pars[NAME] == "NULL"){
    pars[NAME] = inputDir("Zadejte název složky ve které chcete přejmenovat sobory: ", false);
  }
  makeProjectPath();
  loadFiles(PROJECT_PATH);
  cout << "\nNalezené soubory: \n";
  for (Tfile file: files){
    cout << file.name << endl;
  }
  cout << endl;


  if(pars[KACER_DONALD] == "NULL"){inputPar(KACER_DONALD);}
  if(pars[AUTHOR_STRING] == "NULL"){inputPar(AUTHOR_STRING);}
  makeProjectPath();


  string tempIn;
  string tempOut;
  string tempName;

  if(!fs::exists(pars[PROJECT_PATH])){
    cout << "Složka neexitsuje.\n\n";
    return;
  }

  for (Tfile file : files){
    tempIn = pars[PROJECT_PATH] + file.name;
    tempName = file.name;
    replace(tempName, pars[KACER_DONALD], pars[AUTHOR_STRING]);
    tempOut = pars[PROJECT_PATH] + tempName;
    fs::rename(tempIn, tempOut);
  }
  cout << "\n";
  for (Tfile file: files){
    cout << file.name << endl;
  }
  cout << endl;
  unloadFiles();
}

void Cpm::copyFiles(){
  if(pars[ZIP_NAME] == "NULL"){
    pars[ZIP_NAME] = inputDir("Zadejte název složky, ze které chcete soubory kopírovat: ", false);
  }
  if(pars[NAME] == "NULL"){
    pars[NAME] = inputString("Zadejte název složky, do které chcete soubory kopírovat: ", false);
  }
  makeZipDirPath();
  makeProjectPath();
  loadFiles(ZIP_NAME);
  makeDir(pars[PROJECT_PATH]);
  string tempIn, tempOut;
  
  for(Tfile file : files){
    tempIn = pars[ZIP_PATH] + file.name;
    tempOut =  pars[PROJECT_PATH] + file.name;
      if(!fs::exists(tempOut)){
      fs::copy(tempIn, tempOut);
    cout << tempOut + "\n";
    }
  }
  cout << endl;
  unloadFiles();
}

void Cpm::makeDir(string dir){
  if(!fs::exists(dir)){
    fs::create_directory(dir);
  if(fs::exists(dir)){
    cout <<"\nSložka " + dir + " úspěšně vytvořena\n\n";
  } else {
    cout << "ERROR: Složka " + dir + " nemohla být vytvořena\n\n";
  }
  }
} 



void Cpm::wrapCreateMakefile(){
  if(pars[NAME] == "NULL"){
    pars[NAME] = inputDir("Zadejte název projektu ve kterém chcte vytvořit Makefile: ", false);
  }
  if(pars[AUTHOR] == "NULL"){inputPar(AUTHOR);}
  if(pars[LANG_EXT] == "NULL"){inputPar(LANG_EXT);}
  
  makeProjectPath();
  loadFiles(PROJECT_PATH);

  createMakefile();
  unloadFiles();
}

/*
void Cpm::loadOptions(int argc, char *argv[]){
  string sTemp;
  int is_found;
  int j;
  
  for(int i = 1; i < argc; i++){
    sTemp = argv[i];
    if ( args.count(sTemp) > 0 ){

      args[sTemp] = true;
    }
  }
  for (auto const& [key, value]: args){cout << key << ": " << value << endl;}
}
*/

void Cpm::loadFiles(int path){
  if(pars[path] == "NULL"){
    return;
  }

  for (const auto & entry : fs::directory_iterator(pars[path])){
    files.push_back({fs::path(entry).filename()});
  }
}

void Cpm::unloadFiles(){
  int n = files.size();
  for(int i = 0; i < n; i++){
    files.pop_back();
  }
}

void Cpm::makeProjectPath(){
  pars[PROJECT_PATH] = "./" + pars[NAME] + "/";
}

void Cpm::makeZipDirPath(){
  pars[ZIP_PATH] = "./" + pars[ZIP_NAME] + "/";
}

void Cpm::inputPar(int par){
  string temp;
  switch (par) {
    default:
      cout << "Nebyl zadán validní parametr.";
      return;
      break;
    
    case NAME:
      cout << "Zadejte NÁZEV projektu: ";
      getline(cin, pars[par]);
      break;
    
    case AUTHOR_STRING:
      cout << "Zadejte, za co chcete nahradit hledanou část: ";
      getline(cin, pars[par]);
      break;
    
    case AUTHOR:
      cout << "Zadejte AUTORA projektu: ";
      getline(cin, pars[par]);
      break;
    
    case KACER_DONALD:
      cout << "Zadejte, co chcete nahradit: ";
      getline(cin, pars[par]);
      break;
    
    case LANG_EXT:
      cout << "Zadejte JAZYK projektu: ";
      cin >> temp;
      pars[par] = "." + temp;
      break;
    
    case ZIP_NAME:
      cout << "Zadejte NÁZEV složky, kterou chcete kopírovat: ";
      getline(cin, pars[par]);
      break;
  }
  //cin.clear();
  //cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Cpm::createMakefile(){
  if(
      pars[PROJECT_PATH] == "NULL" ||
      pars[NAME] == "NULL" ||
      pars[AUTHOR] == "NULL" ||
      files.empty() ||
      pars[LANG_EXT] == "NULL"
      ){
    return;
  }
  if(!fs::exists(pars[PROJECT_PATH])){
    cout << "Složka projektu neexisuje.\n\n";
    return ;
  }

  string makefilePath = pars[PROJECT_PATH] + "Makefile";
  ofstream makefile(makefilePath);

  makefile << "# Projekt: " << pars[NAME] << endl;
  makefile << "# Autor: " << pars[AUTHOR] << endl;
  // DODĚLAT DATUM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


  makefile << "\n# VARS\nNAME=" << pars[NAME] << "\nSOURCE_FILES=";
  for(Tfile file : files){
    if((file.name.find(pars[LANG_EXT]) != string::npos) && !(file.name.find(".cbp") != string::npos)){
      makefile << file.name << " ";
    }
  }

  string CC;
  if(pars[LANG_EXT] == ".c"){
    CC = "gcc";
  } else if (pars[LANG_EXT] == ".cpp") {
    CC = "g++";
  }

  makefile << "\nCC=" << CC << "\n\nCFLAGS=";
  if (CC == "gcc"){
    makefile << "-std=c99 " ;
  }
  makefile <<  "-pedantic -Wall -g";

  makefile << "\nEXE_FILE=$(NAME)\nALL_FILES=./*"
              "\n\ncompile:\n	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(EXE_FILE)"
              "\n\nrun:\n	./$(EXE_FILE)\n\n\nclear-exe:\n	rm $(EXE_FILE)\n\nclear-bin:\n	rm -rf bin/ \n	rm -rf obj/"
              "\n\nclear-pack:\n	rm $(NAME).tar.gz\n	rm $(NAME).zip"
              "\n\npack: clear-bin\n	tar cvzf $(NAME).tar.gz $(ALL_FILES)\n	zip $(NAME).zip $(ALL_FILES)"
              "\n\nclear: clear-bin clear-pack clear-exe";
    
  if (fs::exists(makefilePath)){
    cout << "Makefile byl úspěšně vytvořen.\n\n";
  } else {
    cout << "ERROR: Makefile nebyl vytvořen.\n\n";
  }
}

string Cpm::inputDir(string message, bool line){
  string result = "NULL" , resultTemp = "NULL";
  

  do {
    resultTemp = inputString(message, line);
    result = "./" + resultTemp + "/";
    if(!fs::exists(result)){
      cout << "  !! Složka neexistuje !!\n";
    }
  }while (!fs::exists(result));

  return resultTemp;
}

string Cpm::inputString(string message, bool line){
  string result = "NULL";
    while(result == "NULL"){
      cout << message;
      if(!line){
        cin >> result;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        getline(cin, result);
      }
    }
    return result;
}

