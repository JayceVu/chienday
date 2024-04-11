#include "glut.h"
#include <stdlib.h>
#include <stdio.h>

float angleX = 0.0;
float angleY = 0.0;
float posX = 0.0;
float posY = 0.0;
float posZ = 0.0;

void veTuSach() {
    // Tủ sách màu hồng
    glColor3f(1.0, 0.5, 0.5); // Màu hồng
    glPushMatrix();
    glTranslatef(0.0, 0.35, -1.7); // Đặt vị trí của tủ sách gần tường hơn
    glRotatef(0, 0.0, 1.0, 0.0); // Xoay tủ về góc 0 độ quanh trục y
    glScalef(0.6, 0.8, 0.2); // Kích thước tủ sách
    glutSolidCube(1.0);
    glPopMatrix();

    // Cánh cửa giữa màu cam
    glColor3f(1.0, 0.5, 0.0); // Màu cam
    glPushMatrix();
    glTranslatef(0.0, 0.35, -1.8); // Đặt vị trí của cánh cửa giữa
    glRotatef(0, 0.0, 1.0, 0.0); // Xoay cánh cửa về góc 0 độ quanh trục y
    glScalef(0.6, 0.8, 0.05); // Kích thước cánh cửa
    glutSolidCube(1.0);
    glPopMatrix();
}

void veGhe() {
    // Thân ghế màu nâu
    glColor3f(0.3, 0.15, 0.05);
    glPushMatrix();
    glTranslatef(0.0, 0.0625, 0.0); // Vị trí ghế đặt trên mặt bàn, giảm chiều cao đi một nửa
    glScalef(0.3, 0.125, 0.3); // Kích thước ghế, giảm chiều cao đi một nửa
    glutSolidCube(1.0);
    glPopMatrix();

    // Đệm ghế màu cam nhạt
    glColor3f(1.0, 0.7, 0.4);
    glPushMatrix();
    glTranslatef(0.0, 0.1375, 0.0); // Vị trí đệm ghế, giảm chiều cao đi một nửa
    glScalef(0.3, 0.025, 0.3); // Kích thước đệm ghế, giảm chiều cao đi một nửa
    glutSolidCube(1.0);
    glPopMatrix();
}

void veTV() {
    // Thân TV màu xanh nước biển
    glColor3f(0.0, 0.5, 0.5); // Màu xanh nước biển
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0); // Vị trí TV đặt trên mặt bàn
    glScalef(0.7, 0.7, 0.02); // Kích thước TV (giữ kích thước, chỉ thay đổi độ dày)
    glutSolidCube(1.0);
    glPopMatrix();

    // Khung TV màu đen (bao phủ một mặt)
    glColor3f(0.0, 0.0, 0.0); // Màu đen
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.01); // Vị trí TV đặt trên mặt bàn, di chuyển khung lên một chút để bao phủ mặt TV
    glScalef(0.92, 0.92, 0.01); // Kích thước khung TV (bao phủ một mặt)
    glutSolidCube(1.0);
    glPopMatrix();

    // Màn hình TV màu đen
    glColor3f(0.0, 0.0, 0.0); // Màu đen
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0); // Vị trí TV đặt trên mặt bàn
    glScalef(0.85, 0.85, 0.01); // Kích thước màn hình TV 
    glutSolidCube(1.0);
    glPopMatrix();

    // Viền xung quang bao quanh màn hình
    glColor4f(0.0, 0.0, 0.0, 0.5); // Màu đen với độ trong suốt
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.005); // Di chuyển lên một chút so với màn hình TV
    glScalef(0.70, 0.70, 0.01); // Kích thước viền xung quang 
    glutSolidCube(1.0);
    glPopMatrix();
}

void veBan() {
    // Vẽ mặt bàn
    glColor3f(0.6, 0.4, 0.2); // Màu vân gỗ
    glBegin(GL_QUADS);
    glVertex3f(-0.375, 0.25, -0.375); // Mặt bàn nằm trên mặt sàn
    glVertex3f(0.375, 0.25, -0.375);
    glVertex3f(0.375, 0.25, 0.375);
    glVertex3f(-0.375, 0.25, 0.375);
    glEnd();

    // Vẽ chân bàn
    glColor3f(0.6, 0.4, 0.2); // Màu vân gỗ
    // Chân bàn ở góc trái dưới
    glBegin(GL_QUADS);
    glVertex3f(-0.35, 0.0, -0.35);
    glVertex3f(-0.25, 0.0, -0.35);
    glVertex3f(-0.25, 0.25, -0.35);
    glVertex3f(-0.35, 0.25, -0.35);
    glEnd();

    // Chân bàn ở góc phải dưới
    glBegin(GL_QUADS);
    glVertex3f(0.25, 0.0, -0.35);
    glVertex3f(0.35, 0.0, -0.35);
    glVertex3f(0.35, 0.25, -0.35);
    glVertex3f(0.25, 0.25, -0.35);
    glEnd();

    // Chân bàn ở góc phải trên
    glBegin(GL_QUADS);
    glVertex3f(0.25, 0.0, 0.35);
    glVertex3f(0.35, 0.0, 0.35);
    glVertex3f(0.35, 0.25, 0.35);
    glVertex3f(0.25, 0.25, 0.35);
    glEnd();

    // Chân bàn ở góc trái trên
    glBegin(GL_QUADS);
    glVertex3f(-0.35, 0.0, 0.35);
    glVertex3f(-0.25, 0.0, 0.35);
    glVertex3f(-0.25, 0.25, 0.35);
    glVertex3f(-0.35, 0.25, 0.35);
    glEnd();
}

void veCanPhong() {
    // Vẽ sàn nhà màu xám
    glColor3f(1.0, 0.0 , 0.0); // Màu xám
    glBegin(GL_QUADS);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(-2.0, 0.0, 2.0);
    glEnd();

    // Vẽ bức tường màu vàng nhạt (cạnh trước)
    glColor3f(0.0, 0.0, 1.0); // Màu vàng nhạt
    glBegin(GL_QUADS);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(2.0, 1.0, -2.0);
    glVertex3f(-2.0, 1.0, -2.0);
    glEnd();

    // Vẽ bức tường màu vàng nhạt (cạnh phải)
    glColor3f(0.8, 0.8, 0.3); // Màu vàng nhạt
    glBegin(GL_QUADS);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(2.0, 1.0, 2.0);
    glVertex3f(2.0, 1.0, -2.0);
    glEnd();

    // Thêm chiếc bàn vào giữa căn phòng
    glPushMatrix();

    // Tính toán vị trí trung điểm của căn phòng
    float midX = (2.0 + (-2.0)) / 2.0;
    float midZ = (2.0 + (-2.0)) / 2.0;

    // Đặt vị trí của chiếc bàn vào trung điểm của căn phòng
    glTranslatef(midX, 0.0, midZ);

    // Vẽ chiếc bàn
    veBan();

    glPopMatrix();

    // Thêm chiếc TV vào bức tường bên phải
    glColor3f(0.8, 0.8, 0.3); // Màu vàng nhạt
    glPushMatrix();
    glTranslatef(1.99, 0.5, 0.0); // Đặt vị trí của chiếc TV tại phía trong bức tường
    glRotatef(90, 0.0, 1.0, 0.0); // Xoay chiếc TV 90 độ để nó nằm ngang trên bức tường
    glScalef(0.9, 0.4, 0.2); // kích thước của TV
    veTV(); // Vẽ chiếc TV
    glPopMatrix();

    // Đặt vị trí cho 4 chiếc ghế
    glPushMatrix();
    glTranslatef(-0.20, 0.0, 0.8); // Vị trí ghế ở góc trái trên
    veGhe();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.20, 0.0, -0.8); // Vị trí ghế ở góc trái dưới
    veGhe();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.20, 0.0, 0.8); // Vị trí ghế ở góc phải trên
    veGhe();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.20, 0.0, -0.8); // Vị trí ghế ở góc phải dưới
    veGhe();
    glPopMatrix();

    veTuSach();
}

void hienThi() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(posX, 2.0 +  posY, 3.0 + posZ, posX, 0.5 + posY, 0.0 + posZ, .0, 1.0, 0.0);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    veCanPhong();

    glutSwapBuffers();
}

void thayDoiKichThuoc(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        angleX -= 2.0f;
        break;
    case 's':
        angleX += 2.0f;
        break;
    case 'a':
        angleY -= 2.0f;
        break;
    case 'd':
        angleY += 2.0f;
        break;
    }
    glutPostRedisplay();
}

void diChuyen(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        posY += 0.1;
        break;
    case GLUT_KEY_DOWN:
        posY -= 0.1;
        break;
    case GLUT_KEY_LEFT:
        posX -= 0.1;
        break;
    case GLUT_KEY_RIGHT:
        posX += 0.1;
        break;
    }
    glutPostRedisplay();
}

// Hàm xử lý sự kiện khi nhấn nút
void specialKeyPressed(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP: // Sử dụng nút mũi tên lên để điều chỉnh góc nhìn xa
        posZ -= 0.1f;
        break;
    case GLUT_KEY_DOWN: // Sử dụng nút mũi tên xuống để điều chỉnh góc nhìn gần
        posZ += 0.1f;
        break;
    case GLUT_KEY_LEFT: // Di chuyển sang trái
        posX -= 0.1f;
        break;
    case GLUT_KEY_RIGHT: // Di chuyển sang phải
        posX += 0.1f;
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Phòng giải trí ");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(hienThi);
    glutReshapeFunc(thayDoiKichThuoc);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(diChuyen);
    glutSpecialFunc(specialKeyPressed); // Đăng ký hàm xử lý sự kiện cho nút mũi tên
    glutMainLoop();
    return 0;
}