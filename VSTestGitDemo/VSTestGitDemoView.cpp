
// VSTestGitDemoView.cpp : implementation of the CVSTestGitDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VSTestGitDemo.h"
#endif

#include "VSTestGitDemoDoc.h"
#include "VSTestGitDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVSTestGitDemoView

IMPLEMENT_DYNCREATE(CVSTestGitDemoView, CView)

BEGIN_MESSAGE_MAP(CVSTestGitDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVSTestGitDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CVSTestGitDemoView construction/destruction

CVSTestGitDemoView::CVSTestGitDemoView()
{
	// TODO: add construction code here

}

CVSTestGitDemoView::~CVSTestGitDemoView()
{
}

BOOL CVSTestGitDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVSTestGitDemoView drawing

void CVSTestGitDemoView::OnDraw(CDC* /*pDC*/)
{
	CVSTestGitDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CVSTestGitDemoView printing


void CVSTestGitDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVSTestGitDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVSTestGitDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVSTestGitDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVSTestGitDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVSTestGitDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVSTestGitDemoView diagnostics

#ifdef _DEBUG
void CVSTestGitDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CVSTestGitDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVSTestGitDemoDoc* CVSTestGitDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVSTestGitDemoDoc)));
	return (CVSTestGitDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CVSTestGitDemoView message handlers
