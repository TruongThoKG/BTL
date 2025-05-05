#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H

#include <iostream> // Thêm để sử dụng cout, cin
#include <fstream>  // Thêm để đọc/ghi file
#include <string>   // Thêm để sử dụng string
#include <vector>   // Thêm để sử dụng vector
#include <map>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

// MAU SAC
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"

// TAI KHOAN ADMIN
const string ADMIN_ID = "admin";
const string ADMIN_PASS = "admin123";

// CAC FILE DU LIEU
const string FILE_SINHVIEN = "sinhvien.txt";
const string FILE_GIANGVIEN = "giangvien.txt";
const string FILE_MONHOC = "monhoc.txt";
const string FILE_DIEM = "diem.txt";
const string FILE_TAIKHOAN = "taikhoan.txt";

// ==================== CÁC HÀM TIỆN ÍCH ====================
void XoaManHinh();
void NhanPhimEnter();
void HienThiTieuDe(const string& tieuDe);

// CLASS TAI KHOAN
class TaiKhoan {
private:
    string TenDangNhap;
    string MatKhau;
    string HoTen;
    string LoaiTaiKhoan;
    int id; // Thêm thuộc tính id
public:
    TaiKhoan(); 
    TaiKhoan(string un, string pw, string fn, string type, int i);// Constructor mặc định
    string GetTenDangNhap() const;
    string GetMatKhau() const;
    string GetHoTen() const;
    string GetLoaiTaiKhoan() const;
    int GetId() const;

    void SetTenDangNhap(const string& un);
    void SetMatKhau(const string& pw);
    void SetHoTen(const string& fn);
    void SetLoaiTaiKhoan(const string& type);
    void SetId(int i);

    void HienThiThongTin() const;
};

// CLASS NGUOI
class Nguoi {
protected:
    string Ma; // Giữ lại kiểu string
    string HoTen;
    string GioiTinh;
    string DiaChi;
    int Tuoi;
public:
	Nguoi();
	Nguoi(string i, string n, string g, string a, int t);
    string GetMa() const;
    string GetHoTen() const;
    string GetGioiTinh() const;
    string GetDiaChi() const;
    int GetTuoi() const;

    void SetMa(const string& i);
    void SetHoTen(const string& n);
    void SetGioiTinh(const string& g);
    void SetDiaChi(const string& a);
    void SetTuoi(int t);

    virtual void NhapThongTin() = 0;
    virtual void HienThiThongTin() const = 0;
};

// CLASS MON HOC
class MonHoc {
private:
    string MaMon;
    string TenMon;
    int SoTinChi;
    string LichHoc; // Thêm lịch học
    string MaGiangVien; // Thêm mã giảng viên
public:
	MonHoc();
	MonHoc(string id, string name, int c, string lh, string maGV);
    string GetMaMon() const;
    string GetTenMon() const;
    int GetSoTinChi() const;
    string GetLichHoc() const;
    string GetMaGiangVien() const;

    void SetMaMon(const string& id);
    void SetTenMon(const string& name);
    void SetSoTinChi(int c);
    void SetLichHoc(const string& lh);
    void SetMaGiangVien(const string& maGV);

    void NhapThongTin();
    void HienThiThongTin() const;
    void HienThiLichHoc() const;
};

// CLASS DIEM
class Diem {
private:
    string MaSinhVien;
    string MaMon;
    float DiemSo;
public:
	Diem();
	Diem(string sid, string cid, float s);
    string GetMaSinhVien() const;
    string GetMaMon() const;
    float GetDiemSo() const;

    void SetMaSinhVien(const string& sid);
    void SetMaMon(const string& cid);
    void SetDiemSo(float s);

    void NhapThongTin();
    void HienThiThongTin() const;
};

// CLASS SINH VIEN
class SinhVien : public Nguoi {
private:
    string ChuyenNganh;
//    vector<string> DSmonDK; // Danh sách môn đăng ký
public:
	vector<string> DSmonDK;
	SinhVien();
	SinhVien(string i, string n, string g, string a, int t, string m);
    string GetChuyenNganh() const;
    void SetChuyenNganh(const string& m);

    void NhapThongTin();
    void HienThiThongTin() const;
    void XemDiem(const vector<Diem>& DanhSachDiem) const;

    // Thêm chức năng đăng ký môn học và xem học phí
    void DKmon(const vector<MonHoc>& DanhSachMonHoc);
    void XemHP(const vector<MonHoc>& DanhSachMonHoc) const;
    vector<string> getDSmonDK() const { return DSmonDK; }
};

// CLASS GIANG VIEN
class GiangVien : public Nguoi {
private:
    string BoMon;
public:
	GiangVien();
	GiangVien(string i, string n, string g, string a, int t, string d);
    string GetBoMon() const;

    void SetBoMon(const string& d);

    void NhapThongTin();
    void HienThiThongTin() const;
    void NhapDiem(vector<Diem>& DanhSachDiem, const vector<SinhVien>& DanhSachSinhVien, const vector<MonHoc>& DanhSachMonHoc);
};

// ==================== CAC HAM LUU FILE ====================
void LuuDanhSachSinhVien(const vector<SinhVien>& DanhSachSinhVien, const string& tenFile);
void LuuDanhSachGiangVien(const vector<GiangVien>& DanhSachGiangVien, const string& tenFile);
void LuuDanhSachMonHoc(const vector<MonHoc>& DanhSachMonHoc, const string& tenFile);
void LuuDanhSachDiem(const vector<Diem>& DanhSachDiem, const string& tenFile);
void LuuDanhSachTaiKhoan(const map<string, TaiKhoan>& DanhSachTaiKhoan, const string&tenFile);

// ==================== CAC HAM DOC FILE ====================
void DocDanhSachSinhVien(vector<SinhVien>& DanhSachSinhVien, const string& tenFile);
void DocDanhSachGiangVien(vector<GiangVien>& DanhSachGiangVien, const string& tenFile);
void DocDanhSachMonHoc(vector<MonHoc>& DanhSachMonHoc, const string& tenFile);
void DocDanhSachDiem(vector<Diem>& DanhSachDiem, const string& tenFile);
void DocDanhSachTaiKhoan(map<string, TaiKhoan>& DanhSachTaiKhoan, const string& tenFile);

// ==================== CÁC HÀM ĐĂNG NHẬP ====================
int ChonLoaiTaiKhoan();
TaiKhoan* DangNhap(map<string, TaiKhoan>& DanhSachTaiKhoan, int loaiTK);

// ==================== CÁC HÀM MENU ====================
void MenuAdmin(vector<SinhVien>& DanhSachSinhVien, vector<GiangVien>& DanhSachGiangVien,
               vector<MonHoc>& DanhSachMonHoc, vector<Diem>& DanhSachDiem,
               map<string, TaiKhoan>& DanhSachTaiKhoan);
void MenuGiangVien(vector<Diem>& DanhSachDiem, const vector<SinhVien>& DanhSachSinhVien,
                  const vector<MonHoc>& DanhSachMonHoc, const string& maGV);
void MenuSinhVien(SinhVien& sv, const vector<Diem>& DanhSachDiem, vector<MonHoc>& DanhSachMonHoc);

// ==================== HAM KHOI TAO MON HOC ====================
void KhoiTaoMonHoc(vector<MonHoc>& DanhSachMonHoc, vector<GiangVien>& DanhSachGiangVien);
void ThietLapMatKhauGiangVien(map<string, TaiKhoan>& DanhSachTaiKhoan);

#endif // QUANLYSINHVIEN_H