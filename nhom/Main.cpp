#include "quanlysinhvien.h"

int main() {
    vector<SinhVien> DanhSachSinhVien;
    vector<GiangVien> DanhSachGiangVien;
    vector<MonHoc> DanhSachMonHoc;
    vector<Diem> DanhSachDiem;
    map<string, TaiKhoan> DanhSachTaiKhoan;

    // Doc du lieu tu file
    DocDanhSachSinhVien(DanhSachSinhVien, FILE_SINHVIEN);
    DocDanhSachGiangVien(DanhSachGiangVien, FILE_GIANGVIEN);
    DocDanhSachMonHoc(DanhSachMonHoc, FILE_MONHOC);
    DocDanhSachDiem(DanhSachDiem, FILE_DIEM);
    DocDanhSachTaiKhoan(DanhSachTaiKhoan, FILE_TAIKHOAN);

    // Khoi tao mon hoc neu danh sach mon hoc trong
    if (DanhSachMonHoc.empty()) {
        KhoiTaoMonHoc(DanhSachMonHoc, DanhSachGiangVien);
    }

    while (true) {
        int loaiTK = ChonLoaiTaiKhoan();
        if (loaiTK == 0) break;

        TaiKhoan* taiKhoan = DangNhap(DanhSachTaiKhoan, loaiTK);

        if (taiKhoan == NULL) {
            NhanPhimEnter();
            continue;
        }

        if (taiKhoan->GetLoaiTaiKhoan() == "admin") {
            MenuAdmin(DanhSachSinhVien, DanhSachGiangVien, DanhSachMonHoc, DanhSachDiem, DanhSachTaiKhoan);
        }
        else if (taiKhoan->GetLoaiTaiKhoan() == "giangvien") {
            string maGV = taiKhoan->GetTenDangNhap();
            MenuGiangVien(DanhSachDiem, DanhSachSinhVien, DanhSachMonHoc, maGV);
        }
        else if (taiKhoan->GetLoaiTaiKhoan() == "sinhvien") {
            string maSV = taiKhoan->GetTenDangNhap();
            bool found = false;
            for (auto& sv : DanhSachSinhVien) {
                if (sv.GetMa() == maSV) {
                    MenuSinhVien(sv, DanhSachDiem, DanhSachMonHoc);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << RED << "Khong tim thay sinh vien co ma " << maSV << RESET << endl;
            }
        }
    }

    cout << GREEN << "\nCam on ban da su dung chuong trinh!" << RESET << endl;
    return 0;
}