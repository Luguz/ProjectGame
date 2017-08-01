
# Rules for creating content for this Project

copyrights by Lukas Guz, Felix Korthals


## identification of variables and functions:


#### function rules :

-    function always typed big
- _  == private function
- \# define "ALL BIG" 0

#### prefixes for variables (not for running variables and "intern" used variables!)

##### generic c++ prefixes
- i     == integer
- ui    == unsigned integer
- vec   == vector
- s     == short
- us    == unsigned short
- l     == long
- ul    == unsigned long
- ll    == long long
- ull   == unsigned long long
- f     == float
- d     == double
- ld    == long double
- str   == string
- b     == bool
- c     == char
- cc    == const* char
- uc    == unsigned char
- cl    == classvariable
- ptr    == pointer (generic pointer)
- IPtr etc == add prefix on Ptr for mor spezific information

##### game Variables specific prefixes
- keep variables free for future implementations
- **List of Categories (important for world vector)**
   * `0-999` == ground types
   * `1000-9999` == building types
   * `10000-99999` ==
- buildings/Units gets to there number a characteristic (for Ex.: 1X, 21R ...)
- **List of characteristics:**

#### use of c++ functionalities:


- objects as class with inherit from main classes (buildings -> military buildings)
- structs?
