#ifndef TOCDLG_H
#define TOCDLG_H

#include <QDialog>
#include <QModelIndex>
#include <QStandardItemModel>

#include "lvdocview.h"
#include "cr3widget.h"
#include "crqtutil.h"

namespace Ui {
	class TocDlg;
}

class CR3View;

class TocDlg : public QDialog {
	Q_OBJECT
	Q_DISABLE_COPY(TocDlg)
public:
	virtual ~TocDlg();
	static bool showDlg(QWidget * parent, CR3View * docView);
protected:
	explicit TocDlg(QWidget *parent, CR3View * docView);
	virtual void changeEvent(QEvent *e);
	bool eventFilter(QObject *obj, QEvent *event);
	void showEvent(QShowEvent *);
private:
	Ui::TocDlg *m_ui;
	CR3View * m_docview;

	int fullStrCount;
	int pageStrCount;
	int pageCount;
	int curPage;
	QString titleMask;
	void fillOpts();
	void updateTitle();
private slots:
	void on_actionGotoPage_triggered();
	void on_actionNextPage_triggered();
	void on_actionPrevPage_triggered();
};

#endif // TOCDLG_H
