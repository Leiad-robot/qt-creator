/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
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
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef TIPCONTENTS_H
#define TIPCONTENTS_H

#include "../utils_global.h"

#include <QString>
#include <QColor>
#include <QWidget>

namespace Utils {

class QTCREATOR_UTILS_EXPORT TipContent
{
protected:
    TipContent();

public:
    virtual ~TipContent();

    virtual TipContent *clone() const = 0;
    virtual int typeId() const = 0;
    virtual bool isValid() const = 0;
    virtual bool isInteractive() const = 0;
    virtual int showTime() const = 0;
    virtual bool equals(const TipContent &tipContent) const = 0;
};

class QTCREATOR_UTILS_EXPORT ColorContent : public TipContent
{
public:
    ColorContent(const QColor &color);
    virtual ~ColorContent();

    virtual TipContent *clone() const;
    virtual int typeId() const;
    virtual bool isValid() const;
    virtual bool isInteractive() const;
    virtual int showTime() const;
    virtual bool equals(const TipContent &tipContent) const;

    const QColor &color() const;

    static const int COLOR_CONTENT_ID = 0;

private:
    QColor m_color;
};

class QTCREATOR_UTILS_EXPORT TextContent : public TipContent
{
public:
    TextContent(const QString &text);
    virtual ~TextContent();

    virtual TipContent *clone() const;
    virtual int typeId() const;
    virtual bool isValid() const;
    virtual bool isInteractive() const;
    virtual int showTime() const;
    virtual bool equals(const TipContent &tipContent) const;

    const QString &text() const;

    static const int TEXT_CONTENT_ID = 1;

private:
    QString m_text;
};

// A content for displaying any widget (with a layout).
class QTCREATOR_UTILS_EXPORT WidgetContent : public TipContent
{
public:
    explicit WidgetContent(QWidget *w, bool interactive = false);

    virtual TipContent *clone() const;
    virtual int typeId() const;
    virtual bool isValid() const;
    virtual int showTime() const;
    virtual bool isInteractive() const;
    void setInteractive(bool i);

    virtual bool equals(const TipContent &tipContent) const;

    // Helper to 'pin' (show as real window) a tooltip shown
    // using WidgetContent
    static bool pinToolTip(QWidget *w, QWidget *parent);

    static const int WIDGET_CONTENT_ID = 42;

    QWidget *widget() const { return m_widget; }

private:
    QWidget *m_widget;
    bool m_interactive;
};

} // namespace Utils

#endif // TIPCONTENTS_H