#include "restrict.h"

#ifdef _WIN32
int strcasecmp(const char* s1, const char* s2){
    bool result = true;
    for(int i=0; s1[i] != '\0'; i++){
        result = result && (tolower( *((unsigned char*) s1++)) == tolower( *((unsigned char*) s2++)));
    }
    return result;
}
#endif
