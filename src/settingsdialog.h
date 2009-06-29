/*
 *  TSPSG - TSP Solver and Generator
 *  Copyright (C) 2007-2009 Lёppa <contacts[at]oleksii[dot]name>
 *
 *  $Id$
 *  $URL$
 *
 *  This file is part of TSPSG.
 *
 *  TSPSG is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  TSPSG is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TSPSG.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "globals.h"
#ifdef Q_OS_WINCE
	#include "ui_settingsdialog.ce.h"
#else
	#include "ui_settingsdialog.h"
#endif // Q_OS_WINCE

class SettingsDialog: public QDialog, public Ui::SettingsDialog
{
	Q_OBJECT
public:
	SettingsDialog(QWidget *parent = 0);

private:
	QSettings *settings;
	QFont font;
	QColor color;
#ifndef Q_OS_WINCE
	bool event(QEvent *);
#endif

private slots:
	void accept();
	void spinRandMinValueChanged(int val) { spinRandMax->setMinimum(val + 1); }
	void buttonFontClicked();
	void buttonColorClicked();
};

#endif // SETTINGSDIALOG_H
