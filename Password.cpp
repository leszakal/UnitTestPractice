#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  bool upper = false;
  bool lower = false;
  for (int i = 0; i < pass.length(); i++) {
    if (isupper(pass[i])) {
      upper = true;
    }
    else if (islower(pass[i])) {
      lower = true;
    }
  }
  if (upper == true && lower == true) {
    return true;
  }
  return false;
}