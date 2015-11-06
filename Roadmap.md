# Base needs #
  1. # Network #
    * **move to libneon**
      * _timeouts_
      * **HeaderParser**
      * list of connections
      * drop needless requests

  1. # ini- or xml- conf file #
    * included conf files
    * GUI front-end (http-)
    * Params from cmd-line and file (cmd-line has priority)

  1. # HTTP Protocol #
    * Referer field
    * Cookies
      * **Fixed**
      * Many-Lines Cookie
        * How Firefox gets this
        * Reproduce Firefox behaviour
    * Standard HTTP request headers

  1. # Proxy #
    * typical proxies
      * Proxy testing
    * Tor

  1. # File handling #
    * File extension is equal second part of MIME, this is wrong
    * **Using MIME instead of file extension for file handling**
    * Dispatch file handling based on regexp or file-extension
      * At this moment two types of file handling - parsing and saving
    * Using file extension to predict MIME and do not request

  1. # Robots.txt #
    * request robots.txt before any page reqested
    * obey robots.txt in requests (or not based on options)

# Improvements #

## _Test Uri handling using collected collection of uris (may be repeat next time)_ ##
  * libwww http://www.w3.org/Library/src/HTParse.c
  * regex http://www.boost.org/doc/libs/1_42_0/tools/inspect/link_check.cpp
    * boost
    * google regex http://code.google.com/p/re2/
    * standard C regex http://www.gnu.org/software/coreutils/manual/libc/Regular-Expressions.html
  * **Gurl http://code.google.com/p/google-url/**
    * **build http://code.google.com/p/python-google-url/wiki/HowToBuildGoogleUrlWithLinux**
  * uriparser http://uriparser.sourceforge.net/doc/html/
  * cpp-netlib http://github.com/cpp-netlib/cpp-netlib/tree/master/boost/network/uri/
  * custom spirit-based
  * **libneon**
  * **htmlcxx**

## Logging ##
  * choose log library

## Unit-tests ##
  * choose unit-test library

## Storage ##
  * tokyo tyrant (cabinet)
    * viewers
  * MySQL
  * store files by uuid, may retrieve by db

## Multi-threaded ##
  * Model
  * Messages

## HTML ##
  * collect examples
  * rewrite htmlcxx on stream for libneon
  * **links not only from**<a><b><ul><li>Rigth order of link visiting - width-first with upper links earlier</li></ul></b>

<h2>Link generation</h2>

<h2>Sessions</h2>
<ul><li>Spider state<br>
</li><li>http front-end