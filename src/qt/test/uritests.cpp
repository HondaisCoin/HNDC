#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("hondaiscoin://G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("hondaiscoin:G8v4Xmchfj8PdCdPaLg6bTGJtZDt8mKT6a?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
