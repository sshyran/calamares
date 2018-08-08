/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2016, Teo Mrnjavac <teo@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PYTHONQTVIEWSTEP_H
#define PYTHONQTVIEWSTEP_H

#include "ViewStep.h"

#include "PythonQt/PythonQtUtils.h"

#include <PythonQt.h>

namespace Calamares
{

class PythonQtViewStep : public Calamares::ViewStep
{
    Q_OBJECT
public:
    PythonQtViewStep( CalamaresUtils::PythonQtModulePtr module,
                      QObject* parent = nullptr );

    QString prettyName() const override;

    QWidget* widget() override;

    void next() override;
    void back() override;
    void onLeave() override;
    void onActivate() override;

    bool isNextEnabled() const override;
    bool isBackEnabled() const override;

    bool isAtBeginning() const override;
    bool isAtEnd() const override;

    JobList jobs() const override;

    void setConfigurationMap( const QVariantMap& configurationMap ) override;

    QWidget* createScriptingConsole();

protected:
    QWidget* m_widget;

private:
    ::PythonQtObjectPtr createViewStep( QWidget* parent );

    CalamaresUtils::PythonQtModulePtr m_pythonModule;
    PythonQtObjectPtr m_obj;
};

}

#endif // PYTHONQTVIEWSTEP_H
