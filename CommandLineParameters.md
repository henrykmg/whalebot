# Configuration #
Using next command line parameters you can configure behavior of your whalebot

```
Web spider options:
  -h [ --help ]                                show this message
  -v [ --version ]                             show version info
  -s [ --site ] arg                            seed Uri
  -d [ --dont-save ]                           dont save fetched pages
  -o [ --one-server ]                          fetch only from one server
  -l [ --link-filter ] arg                     file with words to link filter
  -m [ --max-level ] arg (=0)                  max level of link in one site
  -O [ --output ] arg (=~/web)                 output dir
  -e [ --errorlog ] arg                        path to log file
  -t [ --tmp-file ] arg (=tmp)                 tmp filename
  -u [ --usedlinks ] arg (=usedlinks.txt)      path to used links file
  -f [ --futurelinks ] arg (=futurelinks.txt)  path future links file
  -T [ --connection-timeout ] arg (=5)         connection timeout
  -R [ --read-timeout ] arg (=2)               read timeout
  -M [ --max-connections ] arg (=20)           quantity of simultaneously open connections
  -c [ --collect-links ]                       collect links
  -D [ --dont-save-links ]                     do not save links after stop
  -a [ --ask ]                                 ask after fetching
```

You always can see them using _whalebot -h_

At every moment of crawling push _ENTER_ and fetching stops, you may resume this crawl later