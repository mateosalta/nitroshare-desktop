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

#include "../bundle/bundle.h"
#include "apihandler.h"

QVariantMap ApiHandler::sendFiles(const QVariantMap &params)
{
    // Ensure one of "files" or "directories" was included in the JSON
    if(!params.contains("files") && !params.contains("directories")) {
        return QVariantMap({
            { "error", "either \"files\" or \"directories\" must be included" }
        });
    }

    // Create a new bundle and add each of the files and directories
    Bundle *bundle = new Bundle;
    foreach(QString filename, params.value("files").toStringList()) {
        bundle->addFile(filename);
    }
    foreach(QString path, params.value("directories").toStringList()) {
        bundle->addDirectory(path);
    }

    // TODO: send the bundle

    // An empty map indicates success
    return QVariantMap();
}
