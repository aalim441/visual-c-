# MFC 시작!

---------------------------------------------------------------------------------------------------------------------------------------


### 계산기 (GetDlgItemInt)

* 준비물!
    
    EditControl 3개
    
    Button 1개
 
* 시작!

 1. 먼저 EditControl의 ID를 지정해준다. (지정 안해도 됨)
 
 2. 버튼을 클릭하여 오른쪽 하단에 있는 속성 중 Caption 란에 적혀있는 Button 을 지우고
 원하는 이름을 새긴다.
 
 3. 버튼을 더블클릭 하여 버튼 함수에 접속한다.

// 함수 시작
void CbeginDlg::OnBnClickedButton1()
{
	int a = GetDlgItemInt(IDC_EDIT1);    //a라는 정수에 첫 번째 EditControl 박스에 담긴 값을 담아준다. 괄호 안은 1번에 지정해준 ID
	int b = GetDlgItemInt(IDC_EDIT2);    //b도 마찬가지
	int c = a + b;    // 정수 c에 a와 b값을 더한다.
	SetDlgItemInt(IDC_EDIT3, c);    // 세 번째 editcontrol 박스에 정수 c를 셋팅해준다.
}

---------------------------------------------------------------------------------------------------------------------------------------


### 계산기 (UpdateData(true))

* 준비물!
    
    EditControl 3개
    
    Button 1개

* 시작!

 1. EditControl 박스를 우클릭하여 변수 추가를 선택한다.
 
 2. 범주란에 컨트롤 대신 값으로 선택을 하고 이름을 정해준다.
 
 3. 변수형식은 int 로 지정하고 마침 버튼을 클릭한다.
 
 4. 나머지 2개의 박스도 마찬가지로 설정한다.
 
 5. 버튼을 더블클릭 하여 버튼 함수에 접속한다.
 
 void CbeginDlg::OnBnClickedButton1()
{
	UpdateData(true);   // 컨트롤 값을 변수로 전송한다.
	m_c = m_a+m_b;  // 덧셈연산
	UpdateData(false);  //변수의 값을 컨트롤로 전송한다
}


---------------------------------------------------------------------------------------------------------------------------------------


### 그림판 (pen)

* 시작!

 1. Dialog 박스를 선택한 후 오른쪽 하단 속성창에서 4번째, 메시지 를 클릭하여 WM_ACTIVATE....등이 나오도록 한다.
 
 2. 밑으로 내려 WM_MOUSEMOVE 를 클릭한다.
 
 3. 클릭하면 생기는 화살표 버튼을 눌러 OnMouseMove 를 클릭한다.
 
 CPoint pnt;
 void CPenDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) {      //마우스 왼쪽버튼이 눌러졌을 때 실행
		CClientDC dc(this);        //CClient 객체를 생성.
		CPen pen(PS_SOLID, 16, RGB(0,255,0));   //CPen 클래스. pen(스타일,굵기,색상) -> SOLID,굵기16,녹색으로 설정했다.
		dc.SelectObject(&pen);  // dc에 pen을 넘겨줌.
		dc.MoveTo(pnt);      //MoveTo()좌표에서 LineTo()좌표까지 선을 긋는다. 현재 pnt의 좌표는 0.0이다.
		dc.LineTo(point);    point 는 마우스커서의 위치가 좌표가된다.
	}
	pnt = point;  // point의 값을 pnt에 넣는다. => 마우스의좌표에서 마우스의좌표까지 선을긋는다. => 마우스 왼쪽버튼을 클릭하면 점을 찍게되고 그림을 그릴 수 있다.
	CDialogEx::OnMouseMove(nFlags, point);
}
