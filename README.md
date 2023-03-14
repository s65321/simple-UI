"# simple-UI" 

Designed a MFC UI
**1.	UI should show the current time, and the time shuld keep renewing continuously **
  a. set the Timer, renew the static text per second
  
**2.	Build a List Control, including the information about name, age, and check box**
  a. set Style to implement the check box
  
**3.	Provide a edited field for entering name and age, and the age field only can type in digital number**
  a. when type any word to CEditCtrl, check whether if digital or not. If not, disable the "add" button
  
**4.	Provide the button of delete. Delete the item which is choosed on check box **
  a. GetCheck(), use this API

**5.	When update the List Control item, the scroller bar should always show the newest information**
  a. set the CListCtrl always show the latest line
  b. CListCtrl.SetTopIndex(ChatBox.GetCount() - 1);

**1. Provide a function for exporting the List Control information to csv**
  a. provide a file window for choose the file path

**2. Provide a function for importing the csv information to List Control**
  a. provide a file window for choose the file path
  
**3. As mention above, the contents of the csv content duplicated with List Control are not displayed**
  a. Before importing or Reading the csv information, Open and Read the csv file first
  b. Get the csv content to CString, set in A buffer
  c. Read the CListCtrl information to CString, set in B buffer
  d. Compare A and B, if equal, not import or export
