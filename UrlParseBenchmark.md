# Introduction #

The task is to benchmark existing url parsing algorithms for correctness and time-consuming.

Target is to choose most appropriate parser

Challengers are
  * [my realisation](http://code.google.com/p/whalebot/source/browse/trunk/whalebot/webspider/include/link_factory.h)
  * [google-url](http://code.google.com/p/google-url)
  * [htmlcxx url parse](http://htmlcxx.cvs.sourceforge.net/viewvc/htmlcxx/htmlcxx/html/Uri.h?revision=1.2&view=markup)
  * [libneon](http://www.webdav.org/neon/)


More challengers will be added later.

If you have special wishes, leave a comment.


# Method #

Collect [url collection](http://code.google.com/p/whalebot/downloads/detail?name=links.zip) from webspider fetch session. Using special [app](http://code.google.com/p/whalebot/source/browse/#svn/trunk/url-parsing-benchmark) asses url parsing realisations. Correctness checked based on human judgement (ability to record correct answers will be added later).

Key principle is _use same method for speed and correctness_


# Results #
At this moment only speed tests

|Mark\Parser|my parser|google-url|neon|htmlcxx|
|:----------|:--------|:---------|:---|:------|
|speed, microseconds|499726   |279525    |269892|259033 |
|correctness|0.9575   |1         |0.9971|0.9995 |


# Conclusion #
My parser sucks. I know this. This is the reason of this study.

Google-url may lose because of non-native htmlcxx character replacements. I have no idea how to use GURL::UrlReplacements.

The winner of speed test is **htmlcxx**

**Update1 :**
  1. move out decoding html symbols (for example &amp) from parsing time, because noone of uri-parsing libs do this
  1. move out uri decoding (replace '%3A%2F%2F' to '://'), because it is wrong to send decoded uris to server
google-url and htmlcxx gain significant speedup, but leader is htmlcxx as before

**Update2 :**
  1. I update my notebook, so time is less now
  1. add partial correctness testing (first 2049 urls)
  1. libneon in C and extremly fast, but it fails at urls like 'www.yandex.ua?clid=47656', where slash from host and request part is omitted
  1. htmlcxx fails at urls like '//help.yandex.ru/market/', where protocol type is omitted