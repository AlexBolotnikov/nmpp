#ifndef PRIFILER_INCLUDED
#define PRIFILER_INCLUDED

//! ���������� ���� ������ ������ ����� ������� � ���� S_ProfilerData.funcname
//#include "profiler_def.h"
#include "string.h"
#include "time.h"
#include <stdio.h>
//#define MAX_FUNCNAME_LENGTH 64
#define MAX_FUNCNAME_LENGTH 16

/*! \page intro �������� 
	
	
������ ���������� �������������� ��� �������������� ��������, ������������� ��� ����������� ����������� ��������� NeuroMatrix. 
��������� � ������� ����� �������� ���������� �� ���-�� ������� ������� � ������� �� ���������� � ������������ ������.
��������� ����� ������� � ��������� ����, � xml-�������, � ����� ��� ������������� ��������������� �������� ������ � ���������� �������������� � ������. 
���������� ������������ ������ � ������� ��5101, ��5103, ��6901, MB7707
*/

/*! \page Principle ������� ������ ���������� 

\par �������������
		��� ������ ���������� ������� ������������ ������ ������� ���������� ��������������.  \n
		���� ������ ����������� ������������� � ������� ����������� �������� � ������� ����������� ������� � ���� ������� <_profiler_list>. 
		
		
\code 
		#include "profiler_def.h"
		import from profiler.mlb;

		begin ".text_profiler"
		PROFILER_LIB(MAX_FUNCNAME_LENGTH);

		<_profiler_list>
			...
			PROFILE_FUNC(_myfunc,"myfunc");
			PROFILE_FUNC(_sin,"sin");
			PROFILE_FUNC(_cos,"cos");
			PROFILE_FUNC(_bool._.8.8fullBuffer.1.2,"fullBuffer");
			...
		<_profiler_last>
		return;

		end ".text_profiler";
\endcode

\par 
		��� ������� ��������� ������������ ������������� ���������� ����� ������ ������� _profiler_list . 
		������ ������  PROFILE_FUNC() �� ������ ���������� ������� ���� � ������ ��������������� ������� � ��������� ������� �� ����������� ��� � ������� �������.
		������ ������ �������� ��������� ������  S_ProfilerData � �����  ������� ������������� ���������� � ���������� ������� � ��������� ����������� ������� ������ �������. 
		
\par ����� �����������
  �� ��������� ������ ��������� ���������� �������������� ����������� � ���� �������� ������ �������� S_ProfilerData , �������  ����� ������� ����� stdout  (���� �������� printf) ���� � ��������� ����, ���� � xml-������� � ������� �������� 
  PROFILER_PRINT() � PROFILER_PRINT2XML(). \n
  ����� ������ � ������ ������������� ����� �������� � ���� �������� ������ ���������������� �� ������ ��� ��� ��������. \n
  ������ ����������� �������������� ������� ����� ����� �������� ����� �� �������� ���� � ������� �������� C_Stopwatch. ��� ����������� ������� ���������� ������������ � ������ � ����� ����� ���� ���������� � ������� ��������
  STOPWATCH_PRINT() � STOPWATCH_PRINT2XML(). \n
  
*/


/*! \page manual ����������� �� �������������
	
	
 \par 1. �������� ���������������� ����� 
   \li ������� ���� , �������� � ������ - proflist.asm.\n
   \li ������ � ������� MAX_FUNCNAME_LENGTH (proiler_def.h) ������ ������, ���������� �������� ������� ��� ������ �� �����. ��� ������ ������ ������, ��� ������� ����� ����� ������ ����� �������������� ��� ������. ����������� ������ 8.
   ���� ��� ������� ������ ������� MAX_FUNCNAME_LENGTH , �� ��� ������ ��� ����� ��������. �� ������ ������ ���������� �������� MAX_FUNCNAME_LENGTH �� ������.\n
   \li ���������� ��������������� profiler_06.mlb (��� ����������� NM6405,NM6406) ���� profiler_soc.mlb (��� ������� �� ��������� - ���������� �1879��1� ) \n
   \li �������� ������ ".text_profiler". \n
    \e ����������. C����� .text_profiler ��� ������� �������� ������ ������� ������������� ����������� � ������� ���������� ������. ������� ������, ��� ��� ���� ��� ������ ����� ����� ���� ����������. 
	� ����� ������ ��� �������� ���������������� ������ ������� ����� ����������� � ����������� ������ � ������� ������� profiler_list2table().\n
   \li ����� ������� <_profiler_list> � <_profiler_last> ����������� ����� ������������� ������� ���������� � ������ PROFILE_FUNC() \n
    \e ����������. ��� ��������� ��������� ������� � ������ ����������� � ������ ����� ���: FAdd Mul32 FMul IDiv32 UDiv32 FDiv IMod32 UMod32 LShift32 RShift32 ARShift32 ConvI64toF ConvU64toF
���������� ������������ ������ PROFILE_NONSTD_FUNC()\n
    \e ����������. ����� ������������� ������� ����� ����� �� map-����� , �������������� ������������� ��������� � ������ ������� �������. \n
    \e ����������. �� ��������� ������ ������� map-���� � ����������� �������� �++ ������� �������. ����� ����� ����������  ������� ������� ���������� ������ ���� -full_names \n
	 
	 
	������ ���� profiler.asm:

\code 
const MAX_FUNCNAME_LEN=MAX_FUNCNAME_LENGTH;
import from profiler.mlb;
//import from profiler_soc.mlb; // use profiler_soc.mlb for mc6901 board
begin ".text_profiler"
global _profiler_list:label;
global _profiler_last:label;
<_profiler_list>
	// place here macros with function name for each function you wish to profile like:
	// PROFILE_FUNC(_myfunc,"_myfunc");
	
	PROFILE_FUNC(_mysin,"mysin");
	PROFILE_FUNC(_mycos,"mycos");
	
<_profiler_last>
return;
end ".text_profiler";
\endcode 

\e ����������. ��������������� ���� ����� ������������� ������������� �� ���������� map-�����. 
��������� �������������� �������� \htmlonly <A HREF="http://www.activestate.com/activetcl/downloads">  TCL </A>    \endhtmlonly ������� generate_proflist.tcl �� ����� scripts , ��� � �������� ��������� �����������  ������� ��� map-����� . 
��������:
\verbatim 
tclsh generate_proflist.tcl main.map
\endverbatim
� ���������� ������ ������� ����� ������������ ���� proflist_generated.asm. 
����� ���� ������ ������� ����� ������ ������� �� ����� � ������������� ��� � profile.asm. \n
������� ������, ��� ������ generate_proflist.tcl  �� �������� ����� �� ������ � ������� � � ��������� �������� ����� ������� ����� �� ������.
� ���� ������ ������ ������ ������ ��������� : 
\verbatim 
"DEBUG\DEQUANTIZER.ELF": ERROR LNK415: Symbol "_unsigned._int._const._.8.8Qs.5.7" has different types in different files.
\endverbatim
��������������� ������� ���� ������ ������� 


 
\par 2. ����������� ���������� ����� 
  - ���������� ���������� profiler06.lib , profiler05.lib ��� profiler_soc.lib \n
  - ���������� ���������� nm_io.lib ���� ����� ����������� �������������� �������������� �� stdout  \n
  - �������� ��������������� ���� lib � include ���������� ���������� \n
  - �������� ������ ���������������� ����� proflist.asm \n
  - ������� ���� -fullnames � ���������� ������� 
  
��������:
\verbatim 
nmcc main.cpp -6405 -g          -o.\Release\main.elf     -I..\..\profiler\libprofiler\include -I%NEURO%\include
nmcc proflist.asm -Sc -g -6405  -o.\Release\proflist.elf -I..\..\profiler\libprofiler\include -I%NEURO%\include
linker  -full_names -cmc5101brd.cfg -m -d0 -heap=11000 -o.\example.abs .\Release\main.elf  .\Release\proflist.elf nm_io.lib mc5103lib.lib libc05.lib profiler06.lib cppnew05.lib -l%PROFILER%\lib  -l%NEURO%\lib
\endverbatim


 \par 3. ����������� ����������������� ����� 
 ���������� �������������� ������ ����, ����� ���������� ������ printf  � ����������� ������ .text_profile �� ����������� �� ���������� (������� ������), 
 ��� ����� ������������� ���������� ��������������. \n
 �������� :
 \verbatim
MEMORY
{
	local0:  at 0x00000200, len = 0x00007E00;
	global0: at 0x80000000, len = 0x00008000;
	local1:  at 0x10004000, len = 0x00FFC000;
	global1: at 0xA0000000, len = 0x01000000;
}
SEGMENTS
{
	...
	usercode 	: in local0;
	shared		: in local1;
}

SECTIONS
{
	...
	.rpc_services 		: in shared;		// ���������� ��� printf
	.rpc_services.bss 	: in shared;		// ���������� ��� printf
	.text_profile 		: in usercode;

}
\endverbatim	
	
	
	
 \par 4. ������  ���������� 
 � �������� ����� � �������� main() ���������� ������������ ���� profiler.h � ��������� ������������� ���������� � ������� ����� � ������� ������� profiler_init().


 \code 
#include "profiler.h"

extern "C"{
	int mysin(){
		...
	}
	void mycos(){
		...
	}
};


int main()
{
	...
	PROFILER_PRINT();
	...
	return 1;
}
 \endcode
	
	
 \par 5. ����� ����������� �� ����� ��� � ����

	����� �� �����  (����� stdout) ����������� �������������� �������������� ��������� :
	PROFILER_PRINT() - ����� � ��������� ���� \n
	PROFILER_PRINT2XML() ������������ ����� � ������� xml \n \n
	
	��� ������ ���������� ����� �������� ������� printf ��� ������ �����. \n
	������ ���� ������� �������������� ������������ ���������� nm_io.lib.  \n
	\e ����������. ���������� nm_io.lib ������ ���� ������ � ������ ������������ ���������.
	

	������ ������� � ������ ������� ���������� �� �����: \n
	\verbatim 
	mc5103run example.abs 
	\endverbatim 

	������ ������� � ��������������� ������ � board_stdout.txt : \n
	\verbatim 
	mc5103run example.abs -p 
	\endverbatim 

	
 \par 6. ���������������� ������ � ����������� �������������� 
   ���� printf �� ��������, ������ � ������ ������������� ����� �������� ��������������� �� ������ ��� ��� ��������.  \n\n
   
  \b ������� \b 1. - ������������ ������ ����� ������� ���c��. \n
  ��������������� ������ �������� � ���� �������� ������ �������� S_ProfilerData.
  
  ������ � ������� �������� ����� �������� � ������� ������ ������� profiler_head():
  \code 
  S_ProfilerData* profile_item=profiler_head(); 
  \endcode 
  
  ������ � ��������� ��������� �� ������ - �������������� ����� ����  S_ProfilerData::next . \n
  \e ����������. ������ ������ ������������� � ����������� ������
  
  \b ������� \b 2. - ������ ����� ������� . \n
  �������������� ��������������� ������ ���������� �������� � ���� �������� ������, ������� �� ������ ������  ����������� ��������� � host-������. ����� ���� 
  ������ .text_profiler ����� ����������� � ����������� �����  ���������� ������. � ���� ����� ������������� �������������� ������� ����������� ������ �������� S_ProfilerData �� ������� ����������� ������ � ������� ������� profiler_list2table(). 
  ������������� ������ �� �������� �������� ��������� �������� ������ , �� ��� ���� ����� ������������� ������� � ���� ����������� �������. ���� ������ ����� ��������� 
  � host-������ �� ��� � ������� �� ����� � ������� ����������� �������:
  
  \e nm-���:
  \code
	...
	int count=profiler_count(profiler_head());  // ��������� ���-�� ��������������� ������� � ������
	S_ProfilerData* tbl=(S_ProfilerData*)malloc1(count*sizeof(S_ProfilerData)); // �������� ������� ��� ������� � ����������� ������
	if (tbl==0) return -1;
	profiler_list2table(profiler_head(),tbl);   // �������� ������ �� �������� � ������� � ����������� ������
	ncl_hostSync((int)tbl);                     // �������� ����� �������
	ncl_hostSync((int)profiler_count(tbl));     // �������� ������ �������
	...
  \endcode
  
  \e pc-���:
  \code 
	...
	int addr, count;
	PL_Sync(access,123,&addr);                      // ������ ����� ������ ��������� S_ProfilerData � ����������� ������
	PL_Sync(access,123,&count);                     // ������ ������ �������

	S_ProfilerData* head=new S_ProfilerData[count]; // �������� ������ ��� �������
	PL_ReadMemBlock(access, (PL_Word*) head, addr, count*sizeof(S_ProfilerData)/4);	// �������� �������
	
	profiler_table2list(head,count);                // ��������� ����� � �������
	profiler_char8bit(head);                        // ����������� ������ � 8-������ char ������
	profiler_print(head);                           // �������� ������� ��������������� �������
	...
  \endcode
  
  
  
 \par ���������� 1 :  
� ����� scripts ����������� xsl �������������� -profile.xsl , ����������� ���������� ���������� xml-����� � �������� � ��������������� ��������� ���� . 
���� profile.xsl ��� ���� ������ ��������� ����� � ������ profile.xml.

 \par ���������� 2 :
�������� ������� �������� � ������� ���� int ���� S_ProfilerData::funcname. ��� ����������� ����������� ������ �� host-������ ���������� ������������ ��������� �������������� � ���� char: profiler_char8bit() ��� �������� ������ ������ S_ProfilerData::funcname2char().

 \par ���������� 3 :
��� ���������� � ������ ����������� -O1 ��� -O2 ��������� ����� ����� ������������ ��� inline ������� � � ���� ������ �� �������������� �� ����������.
	
*/


extern "C"{
//!  ��������� �������� ����������� �������������� ��� ����� ������� 
/*!
 �� ������ �������� ��������� ������� ������ �� ������������� ��������. ��������� �� ������ ��������� ��������� ������� profiler_head() 
*/
	void profiler_start();
	void profiler_stop();
	void profiler_reset();
	void profiler_dummy();
	
	
	struct S_ProfilerData {
		S_ProfilerData* next;				///< ��������� �� ��������� ��������� 
		unsigned	funcaddr;				///< ����� �������
		unsigned	calls;					///< ���-�� ������� 
		unsigned	summary;				///< ��������� ����������� ����� (� ������)
		unsigned	funcname[MAX_FUNCNAME_LENGTH];///< ��� ������� ��� ����������� � ���������� (����� �� �������� � �������� ������)
		unsigned	stopwatch;				///< ��������� ����� ������� (�������� ������ t1)
	};
	
	
	//! ������� �������� ������� ������ �������� �������������� � ����������� �������� ������ � ��������� � ����� ������. ����� ������ ������� ��������� ��� �������� ������ ������ � host - ������ � ���� ������� � ����� ����� ����������� ������ � ����������� ������.
	//! \param src_head ��������� �� ������ ��������� � �������� ������.
	//! \param dst_table ��������� �� ������ ��������� � �������������� ������.
	//! \return ���������� ��������� �� ��������� ������� � �������������� ������.
	inline S_ProfilerData* profiler_replace(const S_ProfilerData* src_head,S_ProfilerData* dst_table){
		S_ProfilerData* last;
		while (src_head){
			memcpy(dst_table,src_head,sizeof(S_ProfilerData));
			last=dst_table;
			src_head=src_head->next;
			dst_table->next=dst_table+1;
			dst_table=dst_table->next;
		}
		last->next=0;
		return last;
	}

	//! ������� ��������� ���-�� ������� � ������ ������� � head
	//! \param head ��������� �� ������ ��������� � ������.
	//! \return ���-�� ������� � ������ ������� � head
	inline int profiler_count(S_ProfilerData* head){
		int i=0;
		while (head->next){
			head=head->next;
			i++;
		}
		return i;
	}

//! \}
	



};
#endif 
