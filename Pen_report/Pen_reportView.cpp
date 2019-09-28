
// Pen_reportView.cpp: CPenreportView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "CLine.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pen_report.h"
#endif

#include "Pen_reportDoc.h"
#include "Pen_reportView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenreportView

IMPLEMENT_DYNCREATE(CPenreportView, CView)

BEGIN_MESSAGE_MAP(CPenreportView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_PEN, &CPenreportView::OnSelectPen)
END_MESSAGE_MAP()

// CPenreportView 생성/소멸

CPenreportView::CPenreportView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenreportView::~CPenreportView()
{
}

BOOL CPenreportView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}




// CPenreportView 그리기
COLORREF col = RGB(0, 255, 0);
void CPenreportView::OnDraw(CDC* pDC)
{
	CPenreportDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)


		return;

	int n = pDoc->m_oa.GetSize();
	CLine* p;
	for (int i = 0; i < n; i++) {
		p = (CLine*)pDoc->m_oa[i];
		p->Draw(pDC);
	}
}


// CPenreportView 인쇄

BOOL CPenreportView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenreportView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenreportView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenreportView 진단

#ifdef _DEBUG
void CPenreportView::AssertValid() const
{
	CView::AssertValid();
}

void CPenreportView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenreportDoc* CPenreportView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenreportDoc)));
	return (CPenreportDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenreportView 메시지 처리기


void CPenreportView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags == MK_LBUTTON) {
		CLine* p = new CLine(pnt, point, col);
		GetDocument()->m_oa.Add(p);
		Invalidate(0);
	}
	pnt = point;
	CView::OnMouseMove(nFlags, point);
}

void CPenreportView::OnSelectPen()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		col = dlg.GetColor();
	}
}
