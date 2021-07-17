/* Copyright 2008, 2010, Oracle and/or its affiliates.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <string>
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <iomanip>      // std::setw
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
cout << endl;
std::cout.width(15);
cout << "Running 'SELECT 'Hello World!  AS _message'..." << endl;

try {
  sql::Driver *driver;
  //sql::Connection *con;
  //sql::Statement *stmt;
  //sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  std::unique_ptr< sql::Connection >  con   (driver->connect("tcp://127.0.0.1:3306", "ron", "***!"));
  /* Connect to the MySQL test database */
  con->setSchema("employees");

  std::unique_ptr< sql::Statement > stmt ( con->createStatement());
  std::unique_ptr< sql::ResultSet > res (stmt->executeQuery("SELECT * from employees where emp_no between 11111 and 11120 ;"));
  while (res->next()) {

    string str =    res->getString("first_name");
    // cout<<bitset<20>(str)<<endl;
    //cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
   // cout << res->getString("first_name") << endl;
   // cout << "\t... MySQL says it again: ";
    /* Access column data by numeric offset, 1 is the first column */
    cout 
    << res->getString(1) << " | "
    << res->getString(2) << " | "
    // << std::right  << std::left
    <<setw(15) <<  res->getString(3) << " | "
    <<setw(15)<< res->getString(4) << " | "
    <<setw(5)<< res->getString(5) << " | "
    << res->getString(6) << endl;

    
  }
  //delete res;
  //delete stmt;
  //delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "     << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}


//cl /I "C:\Program Files\MySQL\Connector C++ 8.0\include\jdbc"   "C:\Program Files\MySQL\Connector C++ 8.0\lib64\vs14\mysqlcppconn.lib" mysql1.cpp