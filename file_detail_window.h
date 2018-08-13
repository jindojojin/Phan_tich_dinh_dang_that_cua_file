#ifndef FILE_DETAIL_WINDOW_H
#define FILE_DETAIL_WINDOW_H

#include <QFrame>

namespace Ui {
    class File_Detail_Window;
}

class File_Detail_Window : public QFrame
{
    Q_OBJECT

public:
    explicit File_Detail_Window(QWidget *parent = 0);
    ~File_Detail_Window();
    void setFilePath(QString);
    void setFileInfor(QString);

private:
    Ui::File_Detail_Window *ui;
};

#endif // FILE_DETAIL_WINDOW_H
