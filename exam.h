#ifndef EXAM_H
#define EXAM_H

#include <QDialog>

namespace Ui {
class exam;
}

class exam : public QDialog
{
    Q_OBJECT

public:
    explicit exam(QWidget *parent = nullptr);
    ~exam();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::exam *ui;
};

#endif // EXAM_H
