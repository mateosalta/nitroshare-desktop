/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include <QPixmap>
#include <QFont>

#include "aboutdialog.h"
#include "config.h"

const QString Credits =
    "<html><head><meta name='qrichtext' content='1'/></head><body>"
    "<table><tr><td>Created by:</td>"
    "<td><a href='mailto:nathan@quickmediasolutions.com'>Nathan Osman</a></td></tr>"
    "<tr><td></td><td><a href='mailto:daniel.samrocha@gmail.com'>Daniel San</a>"
    "</td></tr></table></body></html>";

const QString License =
    "The MIT License (MIT)\n\n"

    "Permission is hereby granted, free of charge, to any person obtaining a copy "
    "of this software and associated documentation files (the \"Software\"), to "
    "deal in the Software without restriction, including without limitation the "
    "rights to use, copy, modify, merge, publish, distribute, sublicense, and/or "
    "sell copies of the Software, and to permit persons to whom the Software is "
    "furnished to do so, subject to the following conditions:\n\n"

    "The above copyright notice and this permission notice shall be included in "
    "all copies or substantial portions of the Software.\n\n"

    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
    "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE "
    "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING "
    "FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS "
    "IN THE SOFTWARE.";

AboutDialog::AboutDialog()
{
    setupUi(this);

    lblLogo->setPixmap(QPixmap(":/img/logo.svg").scaled(128, 128));

    QFont font = lblProjectTitle->font();
    font.setBold(true);
    lblProjectTitle->setFont(font);
    lblProjectTitle->setText(PROJECT_NAME);

    lblVersion->setText(QString("Version %1").arg(PROJECT_VERSION));
    lblDescription->setText(PROJECT_DESCRIPTION);

    QString websiteTxt("<html><head/><body><a href=\"%1\">%1</a></body></html>");
    lblWebsite->setText(websiteTxt.arg(PROJECT_WEBSITE));
    lblCopyright->setText(QString("Copyright (c) 2015 - %1").arg(PROJECT_AUTHOR));

    textBrowser->hide();
}

void AboutDialog::onCreditsOrLicenceClicked(bool checked)
{
    if(sender()->objectName() == "btnLicense") {
        textBrowser->setText(License);
        btnCredits->setChecked(false);
    } else if(sender()->objectName() == "btnCredits") {
        textBrowser->setText(Credits);
        btnLicense->setChecked(false);
    }

    textBrowser->setVisible(checked);
    wdtContent->setVisible(!checked);
}
