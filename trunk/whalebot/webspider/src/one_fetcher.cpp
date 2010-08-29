
#include <neon/ne_redirect.h>


#include <header_parser.h>
#include <one_fetcher.h>
#include <whale_link.h>
#include <version.h>
#include <http_const.h>


COneFetcher::COneFetcher()
: m_pConnection(0)
, m_sLastConnectedHost("")
, m_pRequest(0)
{}

bool COneFetcher::connect(CLink const &link)
{
    static std::string  userAgent(kProductName + " / " + kVersion);

    const std::string& targetServer(link.getServer());

    if ((0 != m_pConnection) and (targetServer != m_sLastConnectedHost)) {
        //we need to disconnect from wrong host
        ne_session_destroy(m_pConnection);
        m_pConnection           =   0;
        m_sLastConnectedHost.clear();
    }

    if (0 == m_pConnection) {
        //we need to connect to rigth host

        m_pConnection   =   ne_session_create( kMainProtocol
                                             , targetServer.c_str()
                                             , kDefaultPort );

        ne_redirect_register(m_pConnection);//register for custom redirect handling
        ne_set_connect_timeout(m_pConnection, kDefaultConnectionTimeoutInSec);
        ne_set_useragent(m_pConnection, userAgent.c_str());
        ne_set_read_timeout(m_pConnection, kDefaultReadTimeoutInSec);

        m_sLastConnectedHost    =   targetServer;
    }

    return (0 != m_pConnection);
}


bool COneFetcher::request(CLink const &link)
{
    m_pRequest  =   ne_request_create( m_pConnection
                                     , kMainMethod
                                     , link.getUri().c_str() );

    ne_add_request_header(m_pRequest, kCookieField, link.getCookieForCut().c_str());


    //wait 1 second

    int requestResult(ne_begin_request(m_pRequest));

    return ((NE_OK == requestResult) or (NE_REDIRECT == requestResult));
}

unsigned int COneFetcher::getHeader(CHeaderParser &header, std::ostream &out)
{
    header.setRequest(m_pRequest);
    return ne_get_status(m_pRequest)->code;
 }

bool COneFetcher::getResponse(std::ostream &out)
{

    static char kReadBuffer[kDefaultReadBufferSizeInBytes];// exactly 4kb

    ssize_t  readSize;

    while ((readSize = ne_read_response_block(m_pRequest, kReadBuffer, kDefaultReadBufferSizeInBytes)) > 0) {
        out.write(kReadBuffer, readSize);

    }
    ne_end_request(m_pRequest);

    ne_request_destroy(m_pRequest);
    m_pRequest  =   0;

    return (0 == readSize);
}

COneFetcher::~COneFetcher()
{
    if (0 != m_pConnection) {
        ne_session_destroy(m_pConnection);
    }

    if (0 != m_pRequest) {
        ne_request_destroy(m_pRequest);
    }
}