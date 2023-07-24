/* ---------------------------------------------------------------------

   Copyright IRISA, 2003-2017

   This file is part of Heptane, a tool for Worst-Case Execution Time (WCET)
   estimation.
   APP deposit IDDN.FR.001.510039.000.S.P.2003.000.10600

   Heptane is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Heptane is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details (COPYING.txt).

   See CREDITS.txt for credits of authorship

   ------------------------------------------------------------------------ */

#ifndef DOT_PRINT_H
#define DOT_PRINT_H

#include "Analysis.h"
#include "Generic/CallGraph.h"

// Name of internal attributes used (and removed at the end of the analysis)
#define InternalAttributeNameOK "OK"

/**
 * Graphical printing of CFG structure, using graphwiz
 */
class DotPrint:public Analysis
{
 private:
  string directory;
 public:

  DotPrint (Program * p, string dir);

  /** Checks if all required attributes are in the CFG.
      @return always true (nothing specific to do) 
  */
  bool CheckInputAttributes ();

  /** Performs the analysis
      @return true if successful, false otherwise
  */
  bool PerformAnalysis ();

  /** Remove all private attributes*/
  void RemovePrivateAttributes ();
  
};

#endif

