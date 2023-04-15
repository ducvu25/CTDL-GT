create database QUANLY;
go
use QUANLY;

create table SINHVIEN(
	MaSV varchar(10) primary key,
	HoTen nvarchar(30) not null,
	NgaySinh  date not null ,
	GioiTinh nvarchar(10) not null,
	MaLop varchar(10) ,
	DiaChi nvarchar(30) not null,
	SDT varchar(10),
	Email varchar(35) not null
);
create table GIANGVIEN(
	MaGV varchar(10) primary key,
	TenGV nvarchar(30) not null,
	NgaySinh  date not null ,
	GioiTinh nvarchar(10) not null,
	Khoa varchar(10) ,
	SDT varchar(10) not null,
	Email varchar(35) not null
);
create table TINCHI(
	MaTC varchar(10) primary key,
	TenTC nvarchar(30) not null,
	SoTinTH int not null,
	SoTinLT int not null,
	SVMax int not null,
	SVMin int not null,
	TrangThai int not null,
	MaGVDay varchar(10),
	MaGVOn varchar(10),
	foreign key (MaGVDay) references dbo.GIANGVIEN(MaGV),
	foreign key (MaGVOn) references dbo.GIANGVIEN(MaGV)
);
create table DSDANGKY(
	MaSV varchar(10) not null,
	MaTC varchar(10) not null,
	DiemGiuaKy float,
	DiemCuoiKy float,
	constraint PK_DK primary key (MaSV, MaTC),
	foreign key (MaSV) references dbo.SINHVIEN(MaSV),
	foreign key (MaTC) references dbo.TINCHI(MaTC)
);
