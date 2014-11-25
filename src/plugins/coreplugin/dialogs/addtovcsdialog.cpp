/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://www.qt.io/licensing.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/
#include "addtovcsdialog.h"
#include "ui_addtovcsdialog.h"

#include <QListWidgetItem>

namespace Core {
namespace Internal {

AddToVcsDialog::AddToVcsDialog(QWidget *parent, const QString &title,
                               const QStringList &files, const QString &vcsDisplayName) :
    QDialog(parent),
    ui(new Ui::AddToVcsDialog)
{
    ui->setupUi(this);
    QString addTo = files.size() == 1
            ? tr("Add the file to version control (%1)").arg(vcsDisplayName)
            : tr("Add the files to version control (%1)").arg(vcsDisplayName);

    ui->addFilesLabel->setText(addTo);
    setWindowTitle(title);

    foreach (const QString &file, files) {
        QListWidgetItem *item = new QListWidgetItem(file);
        ui->filesListWidget->addItem(item);
    }
}

AddToVcsDialog::~AddToVcsDialog()
{
    delete ui;
}

} // namespace Internal
} // namespace Core