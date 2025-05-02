#include "quanlysinhvien.h"

void XoaManHinh() {
    system("cls || clear");
}

void NhanPhimEnter() {
    cout << "\n" << GREEN << "Nhan Enter de tiep tuc..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    XoaManHinh();
}

void HienThiTieuDe(const string& tieuDe) {
    cout << CYAN << "+----------------------------------------------------------+" << RESET << endl;
    cout << CYAN << "|                  " << tieuDe << "              |" << RESET << endl;
    cout << CYAN << "+----------------------------------------------------------+" << RESET << endl;
}

// ==================== DINH NGHIA HAM NGOAI CLASS ====================

// TAI KHOAN
string TaiKhoan::GetTenDangNhap() const { return TenDangNhap; }
string TaiKhoan::GetMatKhau() const { return MatKhau; }
string TaiKhoan::GetHoTen() const { return HoTen; }
string TaiKhoan::GetLoaiTaiKhoan() const { return LoaiTaiKhoan; }

void TaiKhoan::SetTenDangNhap(const string& un) { TenDangNhap = un; }
void TaiKhoan::SetMatKhau(const string& pw) { MatKhau = pw; }
void TaiKhoan::SetHoTen(const string& fn) { HoTen = fn; }
void TaiKhoan::SetLoaiTaiKhoan(const string& type) { LoaiTaiKhoan = type; }

void TaiKhoan::HienThiThongTin() const {
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Ten dang nhap:" << RESET << TenDangNhap << endl;
    cout << setw(25) << left << BLUE << "| Ho ten:" << RESET << HoTen << endl;
    cout << setw(25) << left << BLUE << "| Loai tai khoan:" << RESET << LoaiTaiKhoan << endl;
    cout << BLUE << "+------------------------------------+" << RESET << endl;
}

// NGUOI
string Nguoi::GetMa() const { return Ma; }
string Nguoi::GetHoTen() const { return HoTen; }
string Nguoi::GetGioiTinh() const { return GioiTinh; }
string Nguoi::GetDiaChi() const { return DiaChi; }
int Nguoi::GetTuoi() const { return Tuoi; }

void Nguoi::SetMa(const string& i) { Ma = i; }
void Nguoi::SetHoTen(const string& n) { HoTen = n; }
void Nguoi::SetGioiTinh(const string& g) { GioiTinh = g; }
void Nguoi::SetDiaChi(const string& a) { DiaChi = a; }
void Nguoi::SetTuoi(int a) { Tuoi = a; }

// MON HOC
string MonHoc::GetMaMon() const { return MaMon; }
string MonHoc::GetTenMon() const { return TenMon; }
int MonHoc::GetSoTinChi() const { return SoTinChi; }
string MonHoc::GetLichHoc() const { return LichHoc; }
string MonHoc::GetMaGiangVien() const { return MaGiangVien; }

void MonHoc::SetMaMon(const string& id) { MaMon = id; }
void MonHoc::SetTenMon(const string& name) { TenMon = name; }
void MonHoc::SetSoTinChi(int c) { SoTinChi = c; }
void MonHoc::SetLichHoc(const string& lh) { LichHoc = lh; }
void MonHoc::SetMaGiangVien(const string& maGV) { MaGiangVien = maGV; }

void MonHoc::NhapThongTin() {
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Nhap ma mon:" << RESET;
    getline(cin, MaMon);
    cout << setw(25) << left << BLUE << "| Nhap ten mon:" << RESET;
    getline(cin, TenMon);

    while (true) {
        cout << setw(25) << left << BLUE << "| Nhap so tin chi:" << RESET;
        cin >> SoTinChi;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    cout << setw(25) << left << BLUE << "| Nhap lich hoc:" << RESET;
    getline(cin, LichHoc);
    cout << setw(25) << left << BLUE << "| Nhap ma giang vien:" << RESET;
    getline(cin, MaGiangVien);
    cout << BLUE << "+------------------------------------+" << RESET << endl;
}

void MonHoc::HienThiThongTin() const {
    cout << CYAN << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Ma mon:" << RESET << MaMon << endl;
    cout << setw(25) << left << BLUE << "| Ten mon:" << RESET << TenMon << endl;
    cout << setw(25) << left << BLUE << "| So tin chi:" << RESET << SoTinChi << endl;
    cout << setw(25) << left << BLUE << "| Lich hoc:" << RESET << LichHoc << endl;
    cout << setw(25) << left << BLUE << "| Ma giang vien:" << RESET << MaGiangVien << endl;
    cout << CYAN << "+------------------------------------+" << RESET << endl;
}

void MonHoc::HienThiLichHoc() const {
    cout << "| " << setw(10) << left << MaMon << " | "
         << setw(20) << left << TenMon << " | "
         << setw(10) << left << SoTinChi << " | "
         << setw(30) << left << LichHoc << " | "
         << setw(10) << left << MaGiangVien << " |" << endl;
}

// DIEM
string Diem::GetMaSinhVien() const { return MaSinhVien; }
string Diem::GetMaMon() const { return MaMon; }
float Diem::GetDiemSo() const { return DiemSo; }

void Diem::SetMaSinhVien(const string& sid) { MaSinhVien = sid; }
void Diem::SetMaMon(const string& cid) { MaMon = cid; }
void Diem::SetDiemSo(float s) { DiemSo = s; }

void Diem::NhapThongTin() {
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Nhap ma sinh vien:" << RESET;
    getline(cin, MaSinhVien);
    cout << setw(25) << left << BLUE << "| Nhap ma mon:" << RESET;
    getline(cin, MaMon);

    while (true) {
        cout << setw(25) << left << BLUE << "| Nhap diem:" << RESET;
        cin >> DiemSo;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    cout << BLUE << "+------------------------------------+" << RESET << endl;
}

void Diem::HienThiThongTin() const {
    cout << MAGENTA << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Ma SV:" << RESET << MaSinhVien << endl;
    cout << setw(25) << left << BLUE << "| Ma mon:" << RESET << MaMon << endl;
    cout << setw(25) << left << BLUE << "| Diem:" << RESET << DiemSo << endl;
    cout << MAGENTA << "+------------------------------------+" << RESET << endl;
}

// SINH VIEN
string SinhVien::GetChuyenNganh() const { return ChuyenNganh; }

void SinhVien::SetChuyenNganh(const string& m) { ChuyenNganh = m; }

void SinhVien::NhapThongTin() {
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Nhap ma sinh vien:" << RESET;
    getline(cin, Ma);
    cout << setw(25) << left << BLUE << "| Nhap ho ten:" << RESET;
    getline(cin, HoTen);

    // Nhap gioi tinh
    int chonGT;
    while (true) {
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << BLUE << "| Chon gioi tinh:                    |" << RESET << endl;
        cout << BLUE << "| 1. Nam                             |" << RESET << endl;
        cout << BLUE << "| 2. Nu                              |" << RESET << endl;
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << "Lua chon: ";
        cin >> chonGT;
        cin.ignore(); // Đảm bảo loại bỏ ký tự newline

        switch (chonGT) {
            case 1:
                GioiTinh = "Nam";
                break;
            case 2:
                GioiTinh = "Nu";
                break;
            default:
                cout << RED << "Lua chon khong hop le! Vui long chon 1 hoac 2." << RESET << endl;
                continue; // Quay lại vòng lặp để nhập lại
        }
        break; // Thoát khỏi vòng lặp nếu nhập hợp lệ
    }

    cout << setw(25) << left << BLUE << "| Nhap dia chi:" << RESET;
    getline(cin, DiaChi);

    while (true) {
        cout << setw(25) << left << BLUE << "| Nhap tuoi:" << RESET;
        cin >> Tuoi;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    cout << setw(25) << left << BLUE << "| Nhap chuyen nganh:" << RESET;
    getline(cin, ChuyenNganh);
    cout << BLUE << "+------------------------------------+" << RESET << endl;
}

void SinhVien::HienThiThongTin() const {
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Ma SV:" << RESET << Ma << endl;
    cout << setw(25) << left << BLUE << "| Ho ten:" << RESET << HoTen << endl;
    cout << setw(25) << left << BLUE << "| Gioi tinh:" << RESET << GioiTinh << endl;
    cout << setw(25) << left << BLUE << "| Dia chi:" << RESET << DiaChi << endl;
    cout << setw(25) << left << BLUE << "| Tuoi:" << RESET << Tuoi << endl;
    cout << setw(25) << left << BLUE << "| Chuyen nganh:" << RESET << ChuyenNganh << endl;
    cout << BLUE << "+------------------------------------+" << RESET << endl;
}

void SinhVien::XemDiem(const vector<Diem>& DanhSachDiem) const {
    HienThiTieuDe("DIEM CUA SINH VIEN " + HoTen);
    bool coDiem = false;

    cout << YELLOW << "+------------------------------------+" << RESET << endl;
    for (const auto& diem : DanhSachDiem) {
        if (diem.GetMaSinhVien() == Ma) {
            cout << setw(25) << left << BLUE << "| Ma mon:" << RESET << diem.GetMaMon() << " - Diem: " << diem.GetDiemSo() << endl;
            coDiem = true;
        }
    }
    cout << YELLOW << "+------------------------------------+" << RESET << endl;

    if (!coDiem) {
        cout << RED << "Khong co diem nao!" << RESET << endl;
    }
}

void SinhVien::DKmon(const vector<MonHoc>& DanhSachMonHoc) {
    int luaChon;

    while (true) {
        HienThiTieuDe("DANG KY MON HOC");
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << BLUE << "| 1. Xem danh sach mon hoc           |" << RESET << endl;
        cout << BLUE << "| 2. Thoat                           |" << RESET << endl;
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << "Lua chon: ";
        while (true) {
            cin >> luaChon;
            if (cin.fail()) {
                cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore();
                break;
            }
        }

        switch (luaChon) {
            case 1: {
                if (DanhSachMonHoc.empty()) {
                    cout << RED << "Khong co mon hoc nao!" << RESET << endl;
                    break;
                }

                cout << YELLOW << "DANH SACH MON HOC:" << RESET << endl;
                cout << "+-----+------------+----------------------+-----------------------+" << endl;
                cout << "| STT | Ma mon     | Ten mon              | Giang vien             |" << endl;
                cout << "+-----+------------+----------------------+-----------------------+" << endl;

                for (size_t i = 0; i < DanhSachMonHoc.size(); ++i) {
                    cout << "| " << setw(3) << right << i + 1 << " ";
                    cout << "| " << setw(10) << left << DanhSachMonHoc[i].GetMaMon() << " ";
                    cout << "| " << setw(20) << left << DanhSachMonHoc[i].GetTenMon() << " ";
                    cout << "| " << setw(20) << left << DanhSachMonHoc[i].GetMaGiangVien() << " |" << endl;
                }
                cout << "+-----+------------+----------------------+-----------------------+" << endl;

                int monDuocChon;
                while (true) {
                    cout << "Chon mon hoc (nhap STT): ";
                    cin >> monDuocChon;

                    if (cin.fail()) {
                        cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        cin.ignore();
                        break;
                    }
                }

                if (monDuocChon > 0 && monDuocChon <= DanhSachMonHoc.size()) {
                    string maMon = DanhSachMonHoc[monDuocChon - 1].GetMaMon();
                    bool daDangKy = false;
                    for (const string& monDaDK : DSmonDK) {
                        if (monDaDK == maMon) {
                            daDangKy = true;
                            break;
                        }
                    }
                    if (!daDangKy) {
                        DSmonDK.push_back(maMon);
                        cout << GREEN << "Da dang ky mon: " << DanhSachMonHoc[monDuocChon - 1].GetTenMon() << RESET << endl;
                    } else {
                        cout << RED << "Mon hoc nay da duoc dang ky!" << RESET << endl;
                    }
                } else {
                    cout << RED << "Lua chon khong hop le!" << RESET << endl;
                }
                break;
            }
            case 2:
                cout << GREEN << "Thoat dang ky mon." << RESET << endl;
                return;
            default:
                cout << RED << "Lua chon khong hop le!" << RESET << endl;
        }
        NhanPhimEnter();
    }
}

void SinhVien::XemHP(const vector<MonHoc>& DanhSachMonHoc) const {
    int sotinchi = 0;
    HienThiTieuDe("DANH SACH MON HOC DA DANG KY");

    if (DSmonDK.empty()) {
        cout << RED << "Ban chua dang ky mon hoc nao!" << RESET << endl;
        return;
    }

    cout << YELLOW << "+------------------------------------+" << RESET << endl;
    for (const string& maMon : DSmonDK) {
        for (const auto& mh : DanhSachMonHoc) {
            if (maMon == mh.GetMaMon()) {
                cout << setw(25) << left << BLUE << "| " << mh.GetTenMon() << RESET << endl;
                sotinchi += mh.GetSoTinChi();
            }
        }
    }
    cout << YELLOW << "+------------------------------------+" << RESET << endl;
    cout << GREEN << "Tong so tin chi: " << sotinchi << RESET << endl;
}

// GIANG VIEN
string GiangVien::GetBoMon() const { return BoMon; }

void GiangVien::SetBoMon(const string& d) { BoMon = d; }

void GiangVien::NhapThongTin() {
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Nhap ma giang vien:" << RESET;
    getline(cin, Ma);
    cout << setw(25) << left << BLUE << "| Nhap ho ten:" << RESET;
    getline(cin, HoTen);

    // Nhap gioi tinh
    int chonGT;
    while (true) {
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << BLUE << "| Chon gioi tinh:                    |" << RESET << endl;
        cout << BLUE << "| 1. Nam                             |" << RESET << endl;
        cout << BLUE << "| 2. Nu                              |" << RESET << endl;
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << "Lua chon: ";
        cin >> chonGT;
        cin.ignore(); // Đảm bảo loại bỏ ký tự newline

        switch (chonGT) {
            case 1:
                GioiTinh = "Nam";
                break;
            case 2:
                GioiTinh = "Nu";
                break;
            default:
                cout << RED << "Lua chon khong hop le! Vui long chon 1 hoac 2." << RESET << endl;
                continue; // Quay lại vòng lặp để nhập lại
        }
        break; // Thoát khỏi vòng lặp nếu nhập hợp lệ
    }

    cout << setw(25) << left << BLUE << "| Nhap dia chi:" << RESET;
    getline(cin, DiaChi);

    while (true) {
        cout << setw(25) << left << BLUE << "| Nhap tuoi:" << RESET;
        cin >> Tuoi;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    cout << setw(25) << left << BLUE << "| Nhap bo mon:" << RESET;
    getline(cin, BoMon);
    cout << BLUE << "+------------------------------------+" << RESET << endl;
}

void GiangVien::HienThiThongTin() const {
    cout << GREEN << "+------------------------------------+" << RESET << endl;
    cout << setw(25) << left << BLUE << "| Ma GV:" << RESET << Ma << endl;
    cout << setw(25) << left << BLUE << "| Ho ten:" << RESET << HoTen << endl;
    cout << setw(25) << left << BLUE << "| Gioi tinh:" << RESET << GioiTinh << endl;
    cout << setw(25) << left << BLUE << "| Dia chi:" << RESET << DiaChi << endl;
    cout << setw(25) << left << BLUE << "| Tuoi:" << RESET << Tuoi << endl;
    cout << setw(25) << left << BLUE << "| Bo mon:" << RESET << BoMon << endl;
    cout << GREEN << "+------------------------------------+" << RESET << endl;
}

void GiangVien::NhapDiem(vector<Diem>& DanhSachDiem, const vector<SinhVien>& DanhSachSinhVien, const vector<MonHoc>& DanhSachMonHoc) {
    Diem diemMoi;
    string maSV, maMon;

    HienThiTieuDe("NHAP DIEM SINH VIEN");

    cout << YELLOW << "DANH SACH SINH VIEN:" << RESET << endl;
    cout << "+-----+------------+----------------------+" << endl;
    cout << "| STT | Ma SV      | Ho ten               |" << endl;
    cout << "+-----+------------+----------------------+" << endl;
    for (size_t i = 0; i < DanhSachSinhVien.size(); ++i) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(10) << left << DanhSachSinhVien[i].GetMa() << " ";
        cout << "| " << setw(20) << left << DanhSachSinhVien[i].GetHoTen() << " |" << endl;
    }
    cout << "+-----+------------+----------------------+" << endl;

    int svDuocChon;
    while (true) {
        cout << "Chon sinh vien (nhap STT): ";
        cin >> svDuocChon;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    if (svDuocChon <= 0 || svDuocChon > DanhSachSinhVien.size()) {
        cout << RED << "Lua chon khong hop le!" << RESET << endl;
        return;
    }

    maSV = DanhSachSinhVien[svDuocChon - 1].GetMa();

    cout << YELLOW << "DANH SACH MON HOC:" << RESET << endl;
    cout << "+-----+------------+----------------------+------------+" << endl;
    cout << "| STT | Ma mon     | Ten mon              | So TC      |" << endl;
    cout << "+-----+------------+----------------------+------------+" << endl;
    for (size_t i = 0; i < DanhSachMonHoc.size(); ++i) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(10) << left << DanhSachMonHoc[i].GetMaMon() << " ";
        cout << "| " << setw(20) << left << DanhSachMonHoc[i].GetTenMon() << " ";
        cout << "| " << setw(8) << left << DanhSachMonHoc[i].GetSoTinChi() << " |" << endl;
    }
    cout << "+-----+------------+----------------------+------------+" << endl;

    int monDuocChon;
    while (true) {
        cout << "Chon mon hoc (nhap STT): ";
        cin >> monDuocChon;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    if (monDuocChon <= 0 || monDuocChon > DanhSachMonHoc.size()) {
        cout << RED << "Lua chon khong hop le!" << RESET << endl;
        return;
    }

    maMon = DanhSachMonHoc[monDuocChon - 1].GetMaMon();

    float diem;
    while (true) {
        cout << setw(25) << left << BLUE << "| Nhap diem (0-10):" << RESET;
        cin >> diem;

        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    if (diem < 0 || diem > 10) {
        cout << RED << "Diem khong hop le!" << RESET << endl;
        return;
    }

    diemMoi.SetMaSinhVien(maSV);
    diemMoi.SetMaMon(maMon);
    diemMoi.SetDiemSo(diem); // Set điểm vào đối tượng Diem
    DanhSachDiem.push_back(diemMoi);

    cout << GREEN << "Nhap diem thanh cong!" << RESET << endl;
}

// ==================== CAC HAM LUU FILE ====================
void LuuDanhSachSinhVien(const vector<SinhVien>& DanhSachSinhVien, const string& tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto& sv : DanhSachSinhVien) {
            file << sv.GetMa() << "," << sv.GetHoTen() << "," << sv.GetGioiTinh() << ","
                 << sv.GetDiaChi() << "," << sv.GetTuoi() << "," << sv.GetChuyenNganh() << endl;
        }
        file.close();
        cout << GREEN << "Da luu danh sach sinh vien vao file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de luu!" << RESET << endl;
    }
}

void LuuDanhSachGiangVien(const vector<GiangVien>& DanhSachGiangVien, const string& tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto& gv : DanhSachGiangVien) {
            file << gv.GetMa() << "," << gv.GetHoTen() << "," << gv.GetGioiTinh() << ","
                 << gv.GetDiaChi() << "," << gv.GetTuoi() << "," << gv.GetBoMon() << endl;
        }
        file.close();
        cout << GREEN << "Da luu danh sach giang vien vao file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de luu!" << RESET << endl;
    }
}

void LuuDanhSachMonHoc(const vector<MonHoc>& DanhSachMonHoc, const string& tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto& mh : DanhSachMonHoc) {
            file << mh.GetMaMon() << "," << mh.GetTenMon() << "," << mh.GetSoTinChi() << ","
                 << mh.GetLichHoc() << "," << mh.GetMaGiangVien() << endl;
        }
        file.close();
        cout << GREEN << "Da luu danh sach mon hoc vao file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de luu!" << RESET << endl;
    }
}

void LuuDanhSachDiem(const vector<Diem>& DanhSachDiem, const string& tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto& diem : DanhSachDiem) {
            file << diem.GetMaSinhVien() << "," << diem.GetMaMon() << "," << diem.GetDiemSo() << endl;
        }
        file.close();
        cout << GREEN << "Da luu danh sach diem vao file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de luu!" << RESET << endl;
    }
}

void LuuDanhSachTaiKhoan(const map<string, TaiKhoan>& DanhSachTaiKhoan, const string&tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto& tk : DanhSachTaiKhoan) {
            file << tk.second.GetTenDangNhap() << "," << tk.second.GetMatKhau() << ","
                 << tk.second.GetHoTen() << "," << tk.second.GetLoaiTaiKhoan() << "," << tk.second.GetId() << endl;
        }
        file.close();
        cout << GREEN << "Da luu danh sach tai khoan vao file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de luu!" << RESET << endl;
    }
}

// ==================== CAC HAM DOC FILE ====================
void DocDanhSachSinhVien(vector<SinhVien>& DanhSachSinhVien, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            SinhVien sv;
            stringstream ss(line);
            string token;
            vector<string> data;

            while (getline(ss, token, ',')) {
                data.push_back(token);
            }

            if (data.size() == 6) {
                sv.SetMa(data[0]);
                sv.SetHoTen(data[1]);
                sv.SetGioiTinh(data[2]);
                sv.SetDiaChi(data[3]);
                sv.SetTuoi(stoi(data[4]));
                sv.SetChuyenNganh(data[5]);
                DanhSachSinhVien.push_back(sv);
            }
        }
        file.close();
        cout << GREEN << "Da doc danh sach sinh vien tu file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de doc!" << RESET << endl;
    }
}

void DocDanhSachGiangVien(vector<GiangVien>& DanhSachGiangVien, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            GiangVien gv;
            stringstream ss(line);
            string token;
            vector<string> data;

            while (getline(ss, token, ',')) {
                data.push_back(token);
            }

            if (data.size() == 6) {
                gv.SetMa(data[0]);
                gv.SetHoTen(data[1]);
                gv.SetGioiTinh(data[2]);
                gv.SetDiaChi(data[3]);
                gv.SetTuoi(stoi(data[4]));
                gv.SetBoMon(data[5]);
                DanhSachGiangVien.push_back(gv);
            }
        }
        file.close();
        cout << GREEN << "Da doc danh sach giang vien tu file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de doc!" << RESET << endl;
    }
}

void DocDanhSachMonHoc(vector<MonHoc>& DanhSachMonHoc, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            MonHoc mh;
            stringstream ss(line);
            string token;
            vector<string> data;

            while (getline(ss, token, ',')) {
                data.push_back(token);
            }

            if (data.size() == 5) {
                mh.SetMaMon(data[0]);
                mh.SetTenMon(data[1]);
                mh.SetSoTinChi(stoi(data[2]));
                mh.SetLichHoc(data[3]);
                mh.SetMaGiangVien(data[4]);
                DanhSachMonHoc.push_back(mh);
            }
        }
        file.close();
        cout << GREEN << "Da doc danh sach mon hoc tu file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de doc!" << RESET << endl;
    }
}

void DocDanhSachDiem(vector<Diem>& DanhSachDiem, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Diem diem;
            stringstream ss(line);
            string token;
            vector<string> data;

            while (getline(ss, token, ',')) {
                data.push_back(token);
            }

            if (data.size() == 3) {
                diem.SetMaSinhVien(data[0]);
                diem.SetMaMon(data[1]);
                diem.SetDiemSo(stof(data[2]));
                DanhSachDiem.push_back(diem);
            }
        }
        file.close();
        cout << GREEN << "Da doc danh sach diem tu file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de doc!" << RESET << endl;
    }
}

void DocDanhSachTaiKhoan(map<string, TaiKhoan>& DanhSachTaiKhoan, const string& tenFile) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            TaiKhoan tk;
            stringstream ss(line);
            string token;
            vector<string> data;

            while (getline(ss, token, ',')) {
                data.push_back(token);
            }

            if (data.size() == 5) {
                tk.SetTenDangNhap(data[0]);
                tk.SetMatKhau(data[1]);
                tk.SetHoTen(data[2]);
                tk.SetLoaiTaiKhoan(data[3]);
                tk.SetId(stoi(data[4]));
                DanhSachTaiKhoan[tk.GetTenDangNhap()] = tk;
            }
        }
        file.close();
        cout << GREEN << "Da doc danh sach tai khoan tu file: " << tenFile << RESET << endl;
    } else {
        cout << RED << "Khong the mo file de doc!" << RESET << endl;
    }
}

// ==================== CÁC HÀM ĐĂNG NHẬP ====================
int ChonLoaiTaiKhoan() {
    XoaManHinh();
    HienThiTieuDe("HE THONG QUAN LY SINH VIEN");
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << BLUE << "| 1. Quan tri vien                   |" << RESET << endl;
    cout << BLUE << "| 2. Giang vien                      |" << RESET << endl;
    cout << BLUE << "| 3. Sinh vien                       |" << RESET << endl;
	cout << BLUE << "| 0. Thoat                           |" << RESET << endl;
    cout << BLUE << "+------------------------------------+" << RESET << endl;
    cout << "Lua chon: ";

    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail()) {
            cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }
    return choice;
}

TaiKhoan* DangNhap(map<string, TaiKhoan>& DanhSachTaiKhoan, int loaiTK) {
    string tenDangNhap, matKhau;
    int soLanNhapSai = 0;
    const int gioiHanNhapSai = 3;

    switch (loaiTK) {
        case 1: HienThiTieuDe("DANG NHAP QUAN TRI VIEN"); break;
        case 2: HienThiTieuDe("DANG NHAP GIANG VIEN"); break;
        case 3: HienThiTieuDe("DANG NHAP SINH VIEN"); break;
    }

    while (soLanNhapSai < gioiHanNhapSai) {
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << setw(25) << left << BLUE << "| Ten dang nhap:" << RESET;
        getline(cin, tenDangNhap);
        cout << setw(25) << left << BLUE << "| Mat khau:" << RESET;
        getline(cin, matKhau);
        cout << BLUE << "+------------------------------------+" << RESET << endl;

        if (loaiTK == 1 && tenDangNhap == ADMIN_ID && matKhau == ADMIN_PASS) {
            static TaiKhoan admin;
            admin.SetTenDangNhap(ADMIN_ID);
            admin.SetMatKhau(ADMIN_PASS);
            admin.SetHoTen("Quan tri vien");
            admin.SetLoaiTaiKhoan("admin");
            admin.SetId(0); // Set ID cho admin
            return &admin;
        }

        auto it = DanhSachTaiKhoan.find(tenDangNhap);
        if (it != DanhSachTaiKhoan.end() && it->second.GetMatKhau() == matKhau) {
            if ((loaiTK == 2 && it->second.GetLoaiTaiKhoan() == "giangvien") ||
                (loaiTK == 3 && it->second.GetLoaiTaiKhoan() == "sinhvien")) {
                return &(it->second);
            }
        }

        soLanNhapSai++;
        cout << RED << "Dang nhap that bai! Vui long thu lai. (Con " << gioiHanNhapSai - soLanNhapSai << " lan)" << RESET << endl;
        if (soLanNhapSai < gioiHanNhapSai) {
            cout << GREEN << "Nhan Enter de tiep tuc..." << RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << RED << "Ban da nhap sai qua " << gioiHanNhapSai << " lan. Thoat chuong trinh." << RESET << endl;
    return NULL;
}

// ==================== CÁC HÀM MENU ====================
void MenuAdmin(vector<SinhVien>& DanhSachSinhVien, vector<GiangVien>& DanhSachGiangVien,
               vector<MonHoc>& DanhSachMonHoc, vector<Diem>& DanhSachDiem,
               map<string, TaiKhoan>& DanhSachTaiKhoan) {
    int luaChon;
    do {
        XoaManHinh();
        HienThiTieuDe("MENU QUAN TRI VIEN");
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << BLUE << "| 1. Quan ly sinh vien               |" << RESET << endl;
        cout << BLUE << "| 2. Quan ly giang vien              |" << RESET << endl;
        cout << BLUE << "| 3. Quan ly mon hoc                 |" << RESET << endl;
        cout << BLUE << "| 4. Quan ly diem                    |" << RESET << endl;
        cout << BLUE << "| 5. Luu du lieu                     |" << RESET << endl;
        cout << BLUE << "| 6. Upload file                     |" << RESET << endl;
        cout << BLUE << "| 7. Dang xuat                       |" << RESET << endl;
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << "Lua chon: ";
        while (true) {
            cin >> luaChon;
            if (cin.fail()) {
                cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore();
                break;
            }
        }

        switch (luaChon) {
            case 1: {
                XoaManHinh();
                HienThiTieuDe("QUAN LY SINH VIEN");
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << BLUE << "| 1. Them sinh vien                  |" << RESET << endl;
                cout << BLUE << "| 2. Xem danh sach sinh vien         |" << RESET << endl;
                cout << BLUE << "| 3. Tim kiem sinh vien              |" << RESET << endl;
                cout << BLUE << "| 4. Sua thong tin sinh vien         |" << RESET << endl;
                cout << BLUE << "| 5. Xoa sinh vien                   |" << RESET << endl;
                cout << BLUE << "| 0. Tro ve menu chinh               |" << RESET << endl;
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << "Lua chon: ";
                int chon;
                while (true) {
                    cin >> chon;
                    if (cin.fail()) {
                        cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        cin.ignore();
                        break;
                    }
                }

                switch (chon) {
                    case 1: {
                        SinhVien sv;
                        sv.NhapThongTin();

                        // Kiểm tra mã sinh viên đã tồn tại chưa
                        bool maSVTonTai = false;
                        for (const auto& s : DanhSachSinhVien) {
                            if (s.GetMa() == sv.GetMa()) {
                                cout << RED << "Loi: Ma sinh vien da ton tai!" << RESET << endl;
                                maSVTonTai = true;
                                break;
                            }
                        }

                        if (!maSVTonTai) {
                            DanhSachSinhVien.push_back(sv);

                            TaiKhoan tk;
                            tk.SetTenDangNhap(sv.GetMa());
                            tk.SetHoTen(sv.GetHoTen());
                            cout << setw(25) << left << BLUE << "| Nhap mat khau:" << RESET;
                            string pw;
                            getline(cin, pw);
                            tk.SetMatKhau(pw);
                            tk.SetLoaiTaiKhoan("sinhvien");
                            cout << setw(25) << left << BLUE << "| Nhap ID:" << RESET;
                            int id;
                            while (true) {
                                cin >> id;
                                if (cin.fail()) {
                                    cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                } else {
                                    cin.ignore();
                                    break;
                                }
                            }
                            tk.SetId(id); // Nhập và set ID cho tài khoản
                            DanhSachTaiKhoan[sv.GetMa()] = tk;

                            cout << GREEN << "Them sinh vien thanh cong!" << RESET << endl;
                        }
                        break;
                    }
                    case 2: {
                        HienThiTieuDe("DANH SACH SINH VIEN");
                        cout << "+-----+------------+----------------------+----------------------+" << endl;
                        cout << "| STT | Ma SV      | Ho ten               | Chuyen nganh         |" << endl;
                        cout << "+-----+------------+----------------------+----------------------+" << endl;
                        for (size_t i = 0; i < DanhSachSinhVien.size(); ++i) {
                            cout << "| " << setw(3) << right << i + 1 << " ";
                            cout << "| " << setw(10) << left << DanhSachSinhVien[i].GetMa() << " ";
                            cout << "| " << setw(20) << left << DanhSachSinhVien[i].GetHoTen() << " ";
                            cout << "| " << setw(20) << left << DanhSachSinhVien[i].GetChuyenNganh() << " |" << endl;
                        }
                        cout << "+-----+------------+----------------------+----------------------+" << endl;
                        break;
                    }
                    case 3: {
                        string maSV;
                        cout << setw(25) << left << BLUE << "| Nhap ma sinh vien can tim:" << RESET;
                        getline(cin, maSV);
                        bool timThay = false;
                        for (const auto& sv : DanhSachSinhVien) {
                            if (sv.GetMa() == maSV) {
                                sv.HienThiThongTin();
                                timThay = true;
                                break;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay sinh vien co ma " << maSV << RESET << endl;
                        }
                        break;
                    }
                    case 4: {
                        string maSV;
                        cout << setw(25) << left << BLUE << "| Nhap ma sinh vien can sua:" << RESET;
                        getline(cin, maSV);
                        bool timThay = false;
                        for (auto& sv : DanhSachSinhVien) {
                            if (sv.GetMa() == maSV) {
                                sv.NhapThongTin();
                                cout << GREEN << "Sua thong tin sinh vien thanh cong!" << RESET << endl;
                                timThay = true;
                                break;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay sinh vien co ma " << maSV << RESET << endl;
                        }
                        break;
                    }
                    case 5: {
                        string maSV;
                        cout << setw(25) << left << BLUE << "| Nhap ma sinh vien can xoa:" << RESET;
                        getline(cin, maSV);
                        bool timThay = false;
                        auto it = DanhSachSinhVien.begin();
                        while (it != DanhSachSinhVien.end()) {
                            if (it->GetMa() == maSV) {
                                it = DanhSachSinhVien.erase(it); // Gán lại iterator sau khi xóa
                                cout << GREEN << "Xoa sinh vien thanh cong!" << RESET << endl;
                                timThay = true;
                            } else {
                                ++it;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay sinh vien co ma " << maSV << RESET << endl;
                        }
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << RED << "Lua chon khong hop le!" << RESET << endl;
                }
                break;
            }
            case 2: {
                XoaManHinh();
                HienThiTieuDe("QUAN LY GIANG VIEN");
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << BLUE << "| 1. Them giang vien                 |" << RESET << endl;
                cout << BLUE << "| 2. Xem danh sach giang vien        |" << RESET << endl;
                cout << BLUE << "| 3. Tim kiem giang vien             |" << RESET << endl;
                cout << BLUE << "| 4. Sua thong tin giang vien        |" << RESET << endl;
                cout << BLUE << "| 5. Xoa giang vien                  |" << RESET << endl;
                cout << BLUE << "| 0. Tro ve menu chinh               |" << RESET << endl;
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << "Lua chon: ";
                int chon;
                while (true) {
                    cin >> chon;
                    if (cin.fail()) {
                        cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        cin.ignore();
                        break;
                    }
                }

                switch (chon) {
                    case 1: {
                        GiangVien gv;
                        gv.NhapThongTin();

                        // Kiểm tra mã giảng viên đã tồn tại chưa
                        bool maGVTonTai = false;
                        for (const auto& g : DanhSachGiangVien) {
                            if (g.GetMa() == gv.GetMa()) {
                                cout << RED << "Loi: Ma giang vien da ton tai!" << RESET << endl;
                                maGVTonTai = true;
                                break;
                            }
                        }

                        if (!maGVTonTai) {
                            DanhSachGiangVien.push_back(gv);

                            TaiKhoan tk;
                            tk.SetTenDangNhap(gv.GetMa());
                            tk.SetHoTen(gv.GetHoTen());
                            cout << setw(25) << left << BLUE << "| Nhap mat khau:" << RESET;
                            string pw;
                            getline(cin, pw);
                            tk.SetMatKhau(pw);
                            tk.SetLoaiTaiKhoan("giangvien");
                            cout << setw(25) << left << BLUE << "| Nhap ID:" << RESET;
                            int id;
                            while (true) {
                                cin >> id;
                                if (cin.fail()) {
                                    cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                } else {
                                    cin.ignore();
                                    break;
                                }
                            }
                            tk.SetId(id); // Nhập và set ID cho tài khoản
                            DanhSachTaiKhoan[gv.GetMa()] = tk;

                            cout << GREEN << "Them giang vien thanh cong!" << RESET << endl;
                        }
                        break;
                    }
                    case 2: {
                        HienThiTieuDe("DANH SACH GIANG VIEN");
                        cout << "+-----+------------+----------------------+----------------------+" << endl;
                        cout << "| STT | Ma GV      | Ho ten               | Bo mon               |" << endl;
                        cout << "+-----+------------+----------------------+----------------------+" << endl;
                        for (size_t i = 0; i < DanhSachGiangVien.size(); ++i) {
                            cout << "| " << setw(3) << right << i + 1 << " ";
                            cout << "| " << setw(10) << left << DanhSachGiangVien[i].GetMa() << " ";
                            cout << "| " << setw(20) << left << DanhSachGiangVien[i].GetHoTen() << " ";
                            cout << "| " << setw(20) << left << DanhSachGiangVien[i].GetBoMon() << " |" << endl;
                        }
                        cout << "+-----+------------+----------------------+----------------------+" << endl;
                        break;
                    }
                    case 3: {
                        string maGV;
                        cout << setw(25) << left << BLUE << "| Nhap ma giang vien can tim:" << RESET;
                        getline(cin, maGV);
                        bool timThay = false;
                        for (const auto& gv : DanhSachGiangVien) {
                            if (gv.GetMa() == maGV) {
                                gv.HienThiThongTin();
                                timThay = true;
                                break;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay giang vien co ma " << maGV << RESET << endl;
                        }
                        break;
                    }
                    case 4: {
                        string maGV;
                        cout << setw(25) << left << BLUE << "| Nhap ma giang vien can sua:" << RESET;
                        getline(cin, maGV);
                        bool timThay = false;
                        for (auto& gv : DanhSachGiangVien) {
                            if (gv.GetMa() == maGV) {
                                gv.NhapThongTin();
                                cout << GREEN << "Sua thong tin giang vien thanh cong!" << RESET << endl;
                                timThay = true;
                                break;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay giang vien co ma " << maGV << RESET << endl;
                        }
                        break;
                    }
                    case 5: {
                        string maGV;
                        cout << setw(25) << left << BLUE << "| Nhap ma giang vien can xoa:" << RESET;
                        getline(cin, maGV);
                        bool timThay = false;
                        auto it = DanhSachGiangVien.begin();
                        while (it != DanhSachGiangVien.end()) {
                            if (it->GetMa() == maGV) {
                                it = DanhSachGiangVien.erase(it); // Gán lại iterator sau khi xóa
                                cout << GREEN << "Xoa giang vien thanh cong!" << RESET << endl;
                                timThay = true;
                            } else {
                                ++it;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay giang vien co ma " << maGV << RESET << endl;
                        }
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << RED << "Lua chon khong hop le!" << RESET << endl;
                }
                break;
            }
            case 3: {
                XoaManHinh();
                HienThiTieuDe("QUAN LY MON HOC");
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << BLUE << "| 1. Them mon hoc                    |" << RESET << endl;
                cout << BLUE << "| 2. Xem danh sach mon hoc           |" << RESET << endl;
                cout << BLUE << "| 3. Tim kiem mon hoc                |" << RESET << endl;
                cout << BLUE << "| 4. Sua thong tin mon hoc           |" << RESET << endl;
                cout << BLUE << "| 5. Xoa mon hoc                     |" << RESET << endl;
                cout << BLUE << "| 0. Tro ve menu chinh               |" << RESET << endl;
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << "Lua chon: ";
                int chon;
                while (true) {
                    cin >> chon;
                    if (cin.fail()) {
                        cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        cin.ignore();
                        break;
                    }
                }

                switch (chon) {
                    case 1: {
                        MonHoc mh;
                        mh.NhapThongTin();

                        // Kiểm tra mã môn học đã tồn tại chưa
                        bool maMonTonTai = false;
                        for (const auto& m : DanhSachMonHoc) {
                            if (m.GetMaMon() == mh.GetMaMon()) {
                                cout << RED << "Loi: Ma mon hoc da ton tai!" << RESET << endl;
                                maMonTonTai = true;
                                break;
                            }
                        }

                        if (!maMonTonTai) {
                            DanhSachMonHoc.push_back(mh);
                            cout << GREEN << "Them mon hoc thanh cong!" << RESET << endl;
                        }
                        break;
                    }
                    case 2: {
                        HienThiTieuDe("DANH SACH MON HOC");
                        cout << "+-----+------------+----------------------+------------+----------------------+" << endl;
                        cout << "| STT | Ma mon     | Ten mon              | So TC      | Giang vien           |" << endl;
                        cout << "+-----+------------+----------------------+------------+----------------------+" << endl;
                        for (size_t i = 0; i < DanhSachMonHoc.size(); ++i) {
                            cout << "| " << setw(3) << right << i + 1 << " ";
                            cout << "| " << setw(10) << left << DanhSachMonHoc[i].GetMaMon() << " ";
                            cout << "| " << setw(20) << left << DanhSachMonHoc[i].GetTenMon() << " ";
                            cout << "| " << setw(8) << left << DanhSachMonHoc[i].GetSoTinChi() << " ";
                            cout << "| " << setw(18) << left << DanhSachMonHoc[i].GetMaGiangVien() << " |" << endl;
                        }
                        cout << "+-----+------------+----------------------+------------+----------------------+" << endl;
                        break;
                    }
                    case 3: {
                        string maMon;
                        cout << setw(25) << left << BLUE << "| Nhap ma mon hoc can tim:" << RESET;
                        getline(cin, maMon);
                        bool timThay = false;
                        for (const auto& mh : DanhSachMonHoc) {
                            if (mh.GetMaMon() == maMon) {
                                mh.HienThiThongTin();
                                timThay = true;
                                break;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay mon hoc co ma " << maMon << RESET << endl;
                        }
                        break;
                    }
                    case 4: {
                        string maMon;
                        cout << setw(25) << left << BLUE << "| Nhap ma mon hoc can sua:" << RESET;
                        getline(cin, maMon);
                        bool timThay = false;
                        for (auto& mh : DanhSachMonHoc) {
                            if (mh.GetMaMon() == maMon) {
                                mh.NhapThongTin();
                                cout << GREEN << "Sua thong tin mon hoc thanh cong!" << RESET << endl;
                                timThay = true;
                                break;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay mon hoc co ma " << maMon << RESET << endl;
                        }
                        break;
                    }
                    case 5: {
                        string maMon;
                        cout << setw(25) << left << BLUE << "| Nhap ma mon hoc can xoa:" << RESET;
                        getline(cin, maMon);
                        bool timThay = false;
                        auto it = DanhSachMonHoc.begin();
                        while (it != DanhSachMonHoc.end()) {
                            if (it->GetMaMon() == maMon) {
                                it = DanhSachMonHoc.erase(it); // Gán lại iterator sau khi xóa
                                cout << GREEN << "Xoa mon hoc thanh cong!" << RESET << endl;
                                timThay= true;
                            } else {
                                ++it;
                            }
                        }
                        if (!timThay) {
                            cout << RED << "Khong tim thay mon hoc co ma " << maMon << RESET << endl;
                        }
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << RED << "Lua chon khong hop le!" << RESET << endl;
                }
                break;
            }
            case 4: {
                XoaManHinh();
                HienThiTieuDe("QUAN LY DIEM");
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << BLUE << "| 1. Nhap diem sinh vien             |" << RESET << endl;
                cout << BLUE << "| 2. Xem danh sach diem              |" << RESET << endl;
                cout << BLUE << "| 0. Tro ve menu chinh               |" << RESET << endl;
                cout << BLUE << "+------------------------------------+" << RESET << endl;
                cout << "Lua chon: ";
                int chon;
                while (true) {
                    cin >> chon;
                    if (cin.fail()) {
                        cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        cin.ignore();
                        break;
                    }
                }

                switch (chon) {
                    case 1: {
                        GiangVien gv;
                        gv.NhapDiem(DanhSachDiem, DanhSachSinhVien, DanhSachMonHoc);
                        break;
                    }
                    case 2: {
                        HienThiTieuDe("DANH SACH DIEM");
                        cout << "+-----+------------+----------------------+------------+" << endl;
                        cout << "| STT | Ma SV      | Ma mon               | Diem       |" << endl;
                        cout << "+-----+------------+----------------------+------------+" << endl;
                        for (size_t i = 0; i < DanhSachDiem.size(); ++i) {
                            cout << "| " << setw(3) << right << i + 1 << " ";
                            cout << "| " << setw(10) << left << DanhSachDiem[i].GetMaSinhVien() << " ";
                            cout << "| " << setw(20) << left << DanhSachDiem[i].GetMaMon() << " ";
                            cout << "| " << setw(8) << left << DanhSachDiem[i].GetDiemSo() << " |" << endl;
                        }
                        cout << "+-----+------------+----------------------+------------+" << endl;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << RED << "Lua chon khong hop le!" << RESET << endl;
                }
                break;
            }
            case 5: {
                LuuDanhSachSinhVien(DanhSachSinhVien, FILE_SINHVIEN);
                LuuDanhSachGiangVien(DanhSachGiangVien, FILE_GIANGVIEN);
                LuuDanhSachMonHoc(DanhSachMonHoc, FILE_MONHOC);
                LuuDanhSachDiem(DanhSachDiem, FILE_DIEM);
                LuuDanhSachTaiKhoan(DanhSachTaiKhoan, FILE_TAIKHOAN);
                break;
            }
            case 6: {
            	string tenFile;
	            cout << setw(25) << left << BLUE << "| Nhap ten file can upload:" << RESET;
	            getline(cin, tenFile);
	            DocDanhSachSinhVien(DanhSachSinhVien, tenFile);
	            DocDanhSachGiangVien(DanhSachGiangVien, tenFile);
	            DocDanhSachMonHoc(DanhSachMonHoc, tenFile);
	            DocDanhSachDiem(DanhSachDiem, tenFile);
	            DocDanhSachTaiKhoan(DanhSachTaiKhoan, tenFile);
	
	            cout << GREEN << "Upload file thanh cong!" << RESET << endl;
         
				break;
			}
            case 7:
                cout << GREEN << "Dang xuat thanh cong!" << RESET << endl;
                return;
            default:
                cout << RED << "Lua chon khong hop le!" << RESET << endl;
        }
        NhanPhimEnter();
    } while (true);
}

void MenuGiangVien(vector<Diem>& DanhSachDiem, const vector<SinhVien>& DanhSachSinhVien,
                  const vector<MonHoc>& DanhSachMonHoc, const string& maGV) {
    int luaChon;
    do {
        XoaManHinh();
        HienThiTieuDe("MENU GIANG VIEN");
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << BLUE << "| 1. Nhap diem sinh vien             |" << RESET << endl;
        cout << BLUE << "| 2. Xem danh sach diem              |" << RESET << endl;
        cout << BLUE << "| 3. Xem lich day                    |" << RESET << endl;
        cout << BLUE << "| 4. Dang xuat                       |" << RESET << endl;
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << "Lua chon: ";
        while (true) {
            cin >> luaChon;
            if (cin.fail()) {
                cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore();
                break;
            }
        }

        switch (luaChon) {
            case 1: {
                GiangVien gv;
                gv.NhapDiem(DanhSachDiem, DanhSachSinhVien, DanhSachMonHoc);
                break;
            }
            case 2: {
                HienThiTieuDe("DANH SACH DIEM");
                cout << "+-----+------------+----------------------+------------+" << endl;
                cout << "| STT | Ma SV      | Ma mon               | Diem       |" << endl;
                cout << "+-----+------------+----------------------+------------+" << endl;
                for (size_t i = 0; i < DanhSachDiem.size(); ++i) {
                    cout << "| " << setw(3) << right << i + 1 << " ";
                    cout << "| " << setw(10) << left << DanhSachDiem[i].GetMaSinhVien() << " ";
                    cout << "| " << setw(20) << left << DanhSachDiem[i].GetMaMon() << " ";
                    cout << "| " << setw(8) << left << DanhSachDiem[i].GetDiemSo() << " |" << endl;
                }
                cout << "+-----+------------+----------------------+------------+" << endl;
                break;
            }
            case 3: {
                HienThiTieuDe("LICH DAY");
                cout << "+------------+----------------------+------------+--------------------------------+------------+" << endl;
                cout << "| Ma mon     | Ten mon              | So tin chi | Lich hoc                       | Ma GV      |" << endl;
                cout << "+------------+----------------------+------------+--------------------------------+------------+" << endl;

                for (const auto& mh : DanhSachMonHoc) {
                    if (mh.GetMaGiangVien() == maGV) {
                        mh.HienThiLichHoc();
                    }
                }
                cout << "+------------+----------------------+------------+--------------------------------+------------+" << endl;
                break;
            }
            case 4:
                cout << GREEN << "Dang xuat thanh cong!" << RESET << endl;
                break;
            default:
                cout << RED << "Lua chon khong hop le!" << RESET << endl;
        }
        NhanPhimEnter();
    } while (true);
}

void MenuSinhVien(SinhVien& sv, const vector<Diem>& DanhSachDiem, vector<MonHoc>& DanhSachMonHoc) {
    int luaChon;
    do {
        XoaManHinh();
        HienThiTieuDe("MENU SINH VIEN");
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << BLUE << "| 1. Xem thong tin ca nhan           |" << RESET << endl;
        cout << BLUE << "| 2. Xem diem                        |" << RESET << endl;
        cout << BLUE << "| 3. Xem lich hoc                    |" << RESET << endl;
        cout << BLUE << "| 4. Dang ky mon hoc                 |" << RESET << endl;
        cout << BLUE << "| 5. Xem hoc phi                     |" << RESET << endl;
        cout << BLUE << "| 6. Dang xuat                       |" << RESET << endl;
        cout << BLUE << "+------------------------------------+" << RESET << endl;
        cout << "Lua chon: ";
        while (true) {
            cin >> luaChon;
            if (cin.fail()) {
                cout << RED << "Loi: Vui long nhap mot so nguyen." << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore();
                break;
            }
        }

        switch (luaChon) {
            case 1:
                HienThiTieuDe("THONG TIN CA NHAN");
                sv.HienThiThongTin();
                break;
            case 2:
                sv.XemDiem(DanhSachDiem);
                break;
            case 3: {
                HienThiTieuDe("LICH HOC CAC MON");
                cout << "+------------+----------------------+------------+--------------------------------+------------+" << endl;
                cout << "| Ma mon     | Ten mon              | So tin chi | Lich hoc                       | Ma GV      |" << endl;
                cout << "+------------+----------------------+------------+--------------------------------+------------+" << endl;

                for (const auto& mh : DanhSachMonHoc) {
                    bool daDangKy = false;
                    for (const string& maMon : sv.getDSmonDK()) {
                        if (maMon == mh.GetMaMon()) {
                            daDangKy = true;
                            break;
                        }
                    }
                    if (daDangKy) {
                        mh.HienThiLichHoc();
                    }
                }
                cout << "+------------+----------------------+------------+--------------------------------+------------+" << endl;
                break;
            }
            case 4:
                sv.DKmon(DanhSachMonHoc);
                break;
            case 5:
                sv.XemHP(DanhSachMonHoc);
                break;
            case 6:
                cout << GREEN << "Dang xuat thanh cong!" << RESET << endl;
                break;
            default:
                cout << RED << "Lua chon khong hop le!" << RESET << endl;
        }
        NhanPhimEnter();
    } while (true);
}

// ==================== HAM KHOI TAO MON HOC ====================
void KhoiTaoMonHoc(vector<MonHoc>& DanhSachMonHoc, vector<GiangVien>& DanhSachGiangVien) {
    // Tạo giảng viên mẫu
    GiangVien gv1, gv2, gv3, gv4, gv5;
    gv1.SetMa("GV001");
    gv1.SetHoTen("Tran Van A");
    gv1.SetBoMon("Toan");
    DanhSachGiangVien.push_back(gv1);

    gv2.SetMa("GV002");
    gv2.SetHoTen("Le Thi B");
    gv2.SetBoMon("Vat ly");
    DanhSachGiangVien.push_back(gv2);

    gv3.SetMa("GV003");
    gv3.SetHoTen("Nguyen Van C");
    gv3.SetBoMon("CNTT");
    DanhSachGiangVien.push_back(gv3);

    gv4.SetMa("GV004");
    gv4.SetHoTen("Pham Thi D");
    gv4.SetBoMon("Ngoai ngu");
    DanhSachGiangVien.push_back(gv4);

    gv5.SetMa("GV005");
    gv5.SetHoTen("Hoang Van E");
    gv5.SetBoMon("Ky thuat");
    DanhSachGiangVien.push_back(gv5);

    // Kỳ 1
    MonHoc mh1_1;
    mh1_1.SetMaMon("DTVT101");
    mh1_1.SetTenMon("Nhap mon nganh Dien Tu - Vien Thong");
    mh1_1.SetSoTinChi(3);
    mh1_1.SetLichHoc("Thu 2, 4 - Sang");
    mh1_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh1_1);

    MonHoc mh1_2;
    mh1_2.SetMaMon("MAT101");
    mh1_2.SetTenMon("Giai tich 1");
    mh1_2.SetSoTinChi(2);
    mh1_2.SetLichHoc("Thu 3, 5 - Sang");
    mh1_2.SetMaGiangVien("GV001");
    DanhSachMonHoc.push_back(mh1_2);

    MonHoc mh1_3;
    mh1_3.SetMaMon("CS101");
    mh1_3.SetTenMon("Ky thuat lap trinh");
    mh1_3.SetSoTinChi(3);
    mh1_3.SetLichHoc("Thu 2, 4 - Chieu");
    mh1_3.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh1_3);

    MonHoc mh1_4;
    mh1_4.SetMaMon("LA101");
    mh1_4.SetTenMon("Dai so tuyen tinh");
    mh1_4.SetSoTinChi(3);
    mh1_4.SetLichHoc("Thu 3, 5 - Chieu");
    mh1_4.SetMaGiangVien("GV001");
    DanhSachMonHoc.push_back(mh1_4);

    MonHoc mh1_5;
    mh1_5.SetMaMon("PHY101");
    mh1_5.SetTenMon("Vat ly");
    mh1_5.SetSoTinChi(3);
    mh1_5.SetLichHoc("Thu 6 - Sang");
    mh1_5.SetMaGiangVien("GV002");
    DanhSachMonHoc.push_back(mh1_5);

    MonHoc mh1_6;
    mh1_6.SetMaMon("PHY102");
    mh1_6.SetTenMon("Thi nghiem vat ly");
    mh1_6.SetSoTinChi(1);
    mh1_6.SetLichHoc("Thu 6 - Chieu");
    mh1_6.SetMaGiangVien("GV002");
    DanhSachMonHoc.push_back(mh1_6);

    MonHoc mh1_7;
    mh1_7.SetMaMon("DR101");
    mh1_7.SetTenMon("Ve ky thuat");
    mh1_7.SetSoTinChi(2);
    mh1_7.SetLichHoc("Thu 7 - Sang");
    mh1_7.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh1_7);

    MonHoc mh1_8;
    mh1_8.SetMaMon("PE101");
    mh1_8.SetTenMon("Giao duc the chat F1");
    mh1_8.SetSoTinChi(1);
    mh1_8.SetLichHoc("Thu 7 - Chieu");
    mh1_8.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh1_8);

    // Kỳ 2
    MonHoc mh2_1;
    mh2_1.SetMaMon("QP101");
    mh2_1.SetTenMon("Giao duc QP-AN F1");
    mh2_1.SetSoTinChi(3);
    mh2_1.SetLichHoc("Thu 2, 4 - Sang");
    mh2_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_1);

    MonHoc mh2_2;
    mh2_2.SetMaMon("QP102");
    mh2_2.SetTenMon("Giao duc QP-AN F2");
    mh2_2.SetSoTinChi(2);
    mh2_2.SetLichHoc("Thu 3, 5 - Sang");
    mh2_2.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_2);

    MonHoc mh2_3;
    mh2_3.SetMaMon("QP103");
    mh2_3.SetTenMon("Giao duc QP-AN F3");
    mh2_3.SetSoTinChi(1);
    mh2_3.SetLichHoc("Thu 6 - Sang");
    mh2_3.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_3);

    MonHoc mh2_4;
    mh2_4.SetMaMon("QP104");
    mh2_4.SetTenMon("Giao duc QP-AN F4");
    mh2_4.SetSoTinChi(2);
    mh2_4.SetLichHoc("Thu 7 - Sang");
    mh2_4.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_4);

    MonHoc mh2_5;
    mh2_5.SetMaMon("PHI101");
    mh2_5.SetTenMon("Triet hoc Mac - Lenin");
    mh2_5.SetSoTinChi(3);
    mh2_5.SetLichHoc("Thu 2, 4 - Chieu");
    mh2_5.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_5);

    MonHoc mh2_6;
    mh2_6.SetMaMon("MAT102");
    mh2_6.SetTenMon("Giai tich 2");
    mh2_6.SetSoTinChi(2);
    mh2_6.SetLichHoc("Thu 3, 5 - Chieu");
    mh2_6.SetMaGiangVien("GV001");
    DanhSachMonHoc.push_back(mh2_6);

    MonHoc mh2_7;
    mh2_7.SetMaMon("EC101");
    mh2_7.SetTenMon("Ly thuyet mach");
    mh2_7.SetSoTinChi(3);
    mh2_7.SetLichHoc("Thu 6 - Chieu");
    mh2_7.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_7);

    MonHoc mh2_8;
    mh2_8.SetMaMon("PRO101");
    mh2_8.SetTenMon("Ly thuyet xac suat");
    mh2_8.SetSoTinChi(2);
    mh2_8.SetLichHoc("Thu 7 - Chieu");
    mh2_8.SetMaGiangVien("GV001");
    DanhSachMonHoc.push_back(mh2_8);

    MonHoc mh2_9;
    mh2_9.SetMaMon("PE102");
    mh2_9.SetTenMon("Giao duc the chat F2");
    mh2_9.SetSoTinChi(1);
    mh2_9.SetLichHoc("Thu 2 - Sang");
    mh2_9.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh2_9);

    // Kỳ 3
    MonHoc mh3_1;
    mh3_1.SetMaMon("ECO201");
    mh3_1.SetTenMon("Kinh te chinh tri Mac - Lenin");
    mh3_1.SetSoTinChi(2);
    mh3_1.SetLichHoc("Thu 3, 5 - Sang");
    mh3_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_1);

    MonHoc mh3_2;
    mh3_2.SetMaMon("SOC201");
    mh3_2.SetTenMon("Chu nghia xa hoi khoa hoc");
    mh3_2.SetSoTinChi(2);
    mh3_2.SetLichHoc("Thu 6 - Sang");
    mh3_2.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_2);

    MonHoc mh3_3;
    mh3_3.SetMaMon("SIG201");
    mh3_3.SetTenMon("Tin hieu va he thong");
    mh3_3.SetSoTinChi(2);
    mh3_3.SetLichHoc("Thu 7 - Sang");
    mh3_3.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_3);

    MonHoc mh3_4;
    mh3_4.SetMaMon("ECA201");
    mh3_4.SetTenMon("Ky thuat dien tu tuong tu");
    mh3_4.SetSoTinChi(3);
    mh3_4.SetLichHoc("Thu 2, 4 - Chieu");
    mh3_4.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_4);

    MonHoc mh3_5;
    mh3_5.SetMaMon("ECD201");
    mh3_5.SetTenMon("Ky thuat dien tu so");
    mh3_5.SetSoTinChi(2);
    mh3_5.SetLichHoc("Thu 3, 5 - Chieu");
    mh3_5.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_5);

    MonHoc mh3_6;
    mh3_6.SetMaMon("DSA201");
    mh3_6.SetTenMon("Cau truc du lieu va giai thuat");
    mh3_6.SetSoTinChi(3);
    mh3_6.SetLichHoc("Thu 6 - Chieu");
    mh3_6.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh3_6);

    MonHoc mh3_7;
    mh3_7.SetMaMon("ANT201");
    mh3_7.SetTenMon("Anten va truyen song");
    mh3_7.SetSoTinChi(3);
    mh3_7.SetLichHoc("Thu 7 - Chieu");
    mh3_7.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_7);

    MonHoc mh3_8;
    mh3_8.SetMaMon("ITC201");
    mh3_8.SetTenMon("Tin hoc ky thuat trong DT-VT");
    mh3_8.SetSoTinChi(2);
    mh3_8.SetLichHoc("Thu 2, 4 - Sang");
    mh3_8.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh3_8);

    MonHoc mh3_9;
    mh3_9.SetMaMon("PE201");
    mh3_9.SetTenMon("Giao duc the chat F3");
    mh3_9.SetSoTinChi(1);
    mh3_9.SetLichHoc("Thu 3, 5 - Sang");
    mh3_9.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh3_9);

    // Kỳ 4
    MonHoc mh4_1;
    mh4_1.SetMaMon("DSP301");
    mh4_1.SetTenMon("Xu ly tin hieu so");
    mh4_1.SetSoTinChi(3);
    mh4_1.SetLichHoc("Thu 6 - Sang");
    mh4_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh4_1);

    MonHoc mh4_2;
    mh4_2.SetMaMon("CAO301");
    mh4_2.SetTenMon("Cau truc may tinh va he dieu hanh");
    mh4_2.SetSoTinChi(3);
    mh4_2.SetLichHoc("Thu 7 - Sang");
    mh4_2.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh4_2);

    MonHoc mh4_3;
    mh4_3.SetMaMon("ADV301");
    mh4_3.SetTenMon("Ky thuat lap trinh nang cao");
    mh4_3.SetSoTinChi(3);
    mh4_3.SetLichHoc("Thu 2, 4 - Chieu");
    mh4_3.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh4_3);

    MonHoc mh4_4;
    mh4_4.SetMaMon("MET301");
    mh4_4.SetTenMon("Ky thuat do luong dien tu");
    mh4_4.SetSoTinChi(2);
    mh4_4.SetLichHoc("Thu 3, 5 - Chieu");
    mh4_4.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh4_4);

    MonHoc mh4_5;
    mh4_5.SetMaMon("IDE301");
    mh4_5.SetTenMon("Tu tuong Ho Chi Minh");
    mh4_5.SetSoTinChi(2);
    mh4_5.SetLichHoc("Thu 6 - Chieu");
    mh4_5.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh4_5);

    MonHoc mh4_6;
    mh4_6.SetMaMon("ENG301");
    mh4_6.SetTenMon("Tieng Anh / Phap / Nga B1");
    mh4_6.SetSoTinChi(4);
    mh4_6.SetLichHoc("Thu 7 - Chieu");
    mh4_6.SetMaGiangVien("GV004");
    DanhSachMonHoc.push_back(mh4_6);

    MonHoc mh4_7;
    mh4_7.SetMaMon("PE301");
    mh4_7.SetTenMon("Giao duc the chat F4");
    mh4_7.SetSoTinChi(1);
    mh4_7.SetLichHoc("Thu 2 - Sang");
    mh4_7.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh4_7);

    // Kỳ 5
    MonHoc mh5_1;
    mh5_1.SetMaMon("HIS401");
    mh5_1.SetTenMon("Lich su Dang CSVN");
    mh5_1.SetSoTinChi(2);
    mh5_1.SetLichHoc("Thu 3, 5 - Sang");
    mh5_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh5_1);

    MonHoc mh5_2;
    mh5_2.SetMaMon("ENG401");
    mh5_2.SetTenMon("Tieng Anh / Phap / Nga chuyen nganh");
    mh5_2.SetSoTinChi(3);
    mh5_2.SetLichHoc("Thu 6 - Sang");
    mh5_2.SetMaGiangVien("GV004");
    DanhSachMonHoc.push_back(mh5_2);

    MonHoc mh5_3;
    mh5_3.SetMaMon("INF401");
    mh5_3.SetTenMon("Ly thuyet thong tin");
    mh5_3.SetSoTinChi(3);
    mh5_3.SetLichHoc("Thu 7 - Sang");
    mh5_3.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh5_3);

    MonHoc mh5_4;
    mh5_4.SetMaMon("ECE401");
    mh5_4.SetTenMon("Thuc tap dien tu");
    mh5_4.SetSoTinChi(2);
    mh5_4.SetLichHoc("Thu 2, 4 - Chieu");
    mh5_4.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh5_4);

    MonHoc mh5_5;
    mh5_5.SetMaMon("MIC401");
    mh5_5.SetTenMon("Ky thuat vi xu ly");
    mh5_5.SetSoTinChi(3);
    mh5_5.SetLichHoc("Thu 3, 5 - Chieu");
    mh5_5.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh5_5);

    MonHoc mh5_6;
    mh5_6.SetMaMon("NET401");
    mh5_6.SetTenMon("Mang Vien thong");
    mh5_6.SetSoTinChi(2);
    mh5_6.SetLichHoc("Thu 6 - Chieu");
    mh5_6.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh5_6);

    MonHoc mh5_7;
    mh5_7.SetMaMon("DBS401");
    mh5_7.SetTenMon("Co so thong tin so");
    mh5_7.SetSoTinChi(3);
    mh5_7.SetLichHoc("Thu 7 - Chieu");
    mh5_7.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh5_7);

    // Kỳ 6
    MonHoc mh6_1;
    mh6_1.SetMaMon("OPT501");
    mh6_1.SetTenMon("Ky thuat thong tin quang");
    mh6_1.SetSoTinChi(3);
    mh6_1.SetLichHoc("Thu 2, 4 - Sang");
    mh6_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh6_1);

    MonHoc mh6_2;
    mh6_2.SetMaMon("MOB501");
    mh6_2.SetTenMon("Ky thuat thong tin vo tuyen");
    mh6_2.SetSoTinChi(3);
    mh6_2.SetLichHoc("Thu 3, 5 - Sang");
    mh6_2.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh6_2);

    MonHoc mh6_3;
    mh6_3.SetMaMon("COM501");
    mh6_3.SetTenMon("Thiet ke mang");
    mh6_3.SetSoTinChi(3);
    mh6_3.SetLichHoc("Thu 6 - Sang");
    mh6_3.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh6_3);

    MonHoc mh6_4;
    mh6_4.SetMaMon("SEC501");
    mh6_4.SetTenMon("An toan va bao mat mang");
    mh6_4.SetSoTinChi(3);
    mh6_4.SetLichHoc("Thu 7 - Sang");
    mh6_4.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh6_4);

    MonHoc mh6_5;
    mh6_5.SetMaMon("EMB501");
    mh6_5.SetTenMon("He thong nhung");
    mh6_5.SetSoTinChi(3);
    mh6_5.SetLichHoc("Thu 2, 4 - Chieu");
    mh6_5.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh6_5);

    MonHoc mh6_6;
    mh6_6.SetMaMon("IOT501");
    mh6_6.SetTenMon("Internet of Things");
    mh6_6.SetSoTinChi(3);
    mh6_6.SetLichHoc("Thu 3, 5 - Chieu");
    mh6_6.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh6_6);

    MonHoc mh6_7;
    mh6_7.SetMaMon("CLO501");
    mh6_7.SetTenMon("Dien toan dam may");
    mh6_6.SetSoTinChi(3);
    mh6_6.SetLichHoc("Thu 6 - Chieu");
    mh6_6.SetMaGiangVien("GV003");
    DanhSachMonHoc.push_back(mh6_6);

    // Kỳ 7
    MonHoc mh7_1;
    mh7_1.SetMaMon("PRO601");
    mh7_1.SetTenMon("Do an chuyen nganh");
    mh7_1.SetSoTinChi(3);
    mh7_1.SetLichHoc("Thu 7 - Sang");
    mh7_1.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh7_1);

    MonHoc mh7_2;
    mh7_2.SetMaMon("PRO602");
    mh7_2.SetTenMon("Thuc tap tot nghiep");
    mh7_2.SetSoTinChi(3);
    mh7_2.SetLichHoc("Thu 2, 4 - Chieu");
    mh7_2.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh7_2);

    MonHoc mh7_3;
    mh7_3.SetMaMon("PRO603");
    mh7_3.SetTenMon("Khoa luan tot nghiep");
    mh7_3.SetSoTinChi(3);
    mh7_3.SetLichHoc("Thu 3, 5 - Chieu");
    mh7_3.SetMaGiangVien("GV005");
    DanhSachMonHoc.push_back(mh7_3);

    cout << GREEN << "Da khoi tao danh sach mon hoc mau!" << RESET << endl;
}