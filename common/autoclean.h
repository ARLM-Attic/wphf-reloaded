/*
WPHFMON - Winprint HylaFAX port monitor
Copyright (C) 2011 Monti Lorenzo

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef _AUTOCLEAN_H
#define _AUTOCLEAN_H

#include <windows.h>

class CAutoCriticalSection
{
public:
	CAutoCriticalSection(CRITICAL_SECTION* pCritSect);
	virtual ~CAutoCriticalSection();

private:
	CRITICAL_SECTION* m_pCritSect;
};

class CPrinterHandle
{
public:
	CPrinterHandle(LPWSTR szPrinterName, LPPRINTER_DEFAULTSW pDefaults = NULL);
	CPrinterHandle(LPWSTR szPrinterName, ACCESS_MASK DesiredAccess);
	virtual ~CPrinterHandle();
	operator HANDLE() const { return m_hHandle; }
	HANDLE Handle() const { return m_hHandle; }
private:
	HANDLE m_hHandle;
};

#endif
