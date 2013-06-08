SuperDelete
===========

Deletes a file with a REALLY long file name.


Why Use This?
-------------

A while ago, I made a program with a bug in it. Altough it was only a trivial bug, 
the results from its execution proved to be quite messy. My program, written in Java,
had created a file with an exceptionally long file name. This file name was so long that
Windows was not able to move, rename, or delete it. The command prompt proved to be equally
useless. 

Actually, I initially had 3 files that were too long to delete. Using the command:
~~~
dir /x
~~~

I was able to find the "short name" of each of those files. By referring to these short names,
I was able to delete one of them using:
~~~
erase SHORTFILENAME
~~~
However, this failed to work for the other two. No other method yielded frutiful results until I found 
[this page](http://www.codinghorror.com/blog/2006/11/filesystem-paths-how-long-is-too-long.html). Bascially,
the part of the article that helps us is that we are able to bypass the 256 character limit through the use
of the Windows API. By prepending \\?\ to an absolute path, we can extend the max to over 32,000 characters!

So I put together a little program I call Super Delete. Pass in the absolute path of a file you need to delete and
it'll do it, even if the file name is extremely long.

~~~c++
#include <Windows.h>
#include <string>

using namespace std;

int main(){
  // Absolute path to file, with \\?\ prepended
  string path = "\\\\?\\C:\\Users\\Path\\To\\Long\\FILENAME.txt";
  const char * arr = path.c_str();
  
  // Call DeleteFile from the Windows API
  DeleteFile(arr);

  // And That's it!
  return 0;
}
~~~

