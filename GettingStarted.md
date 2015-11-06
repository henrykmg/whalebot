# Supported OS #
Developed under Fedora
But in theory everywhere you have htmlcxx, icu, google-url and boost - you have whalebot

# Dependencies #
  * [htmlcxx v 0.84](http://htmlcxx.sourceforge.net/)
  * [boost](http://www.boost.org/) now used asio, program options, filesystem, algorithm string, unordered map, thread, date\_time and other
  * custom libs in svn
  * google-url in svn depends on [icu](http://site.icu-project.org/)

# Build system #
In [release-0.01.00](http://code.google.com/p/whalebot/source/browse/#svn/tags/release-0.01.00) moved to [cmake](http://cmake.org/)

to build
```
cmake -DCMAKE_BUILD_TYPE=Release .
make
sudo make install
```

# Start-crawl #

```
whalebot -s http://google.com -O ~/web
```

  1. Wait for some time
  1. Wait again
  1. ...
  1. **THE WHOLE INTERNET** on your hard drive :)

For more accurate parameters tuning see CommandLineParameters