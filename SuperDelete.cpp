#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

/**
 * Deletes a file. Not just any file, one with a REALLY long file path
 */
int main(int argc, char* argv[]){
  // Argument for program is the COMPLETE file path
  // Something like C:\Users\...\Reallylongfilepath.txt,
  // If there are spaces, wrap the entire path around quotes
  if(argc < 2){
    cout << "No path name entered";
  }else{
    int successCount = 0;

    for(int i = 1; i < argc; i ++){
      // Prepend \\?\ to tell the Windows API that we want to extend the max 
      // file path length to more than 256 characters
      string path = argv[i];
      string str = "\\\\?\\" + path;
      const char * chArr = str.c_str();

      // Try to delete it, might fail if you don't have the appropriate permissions
      int result = DeleteFile(chArr);

      if(result == 0){
        cout << "Error Deleting File: " << path << endl;
      }else{
        successCount ++;
        cout << "Deleted File: " << path << endl;
      }
    }

    cout << successCount << " File(s) Deleted" << endl;
  }
  return 0;
}