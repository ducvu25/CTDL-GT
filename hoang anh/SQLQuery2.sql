use QUANLY;
select * from GIANGVIEN
where TenGV like 'Lan';

select * from DSDANGKY
where MaTC = 'MAT2223 49' and DiemCuoiKy > 9;

select Count(MaSV) as 'So luong' from DSDANGKY
where MaTC = 'INT2223 48'
group by MaTC;

select MaTC, TenTC, Bang1.TenGV as 'Giang vien day', GIANGVIEN.TenGV as 'Giang vien on tap' from(
	select MaTC, TenTC, TenGV, MaGVOn from TINCHI
	join GIANGVIEN 
	on TINCHI.MaGVDay = GIANGVIEN.MaGV) as Bang1
join GIANGVIEN on Bang1.MaGVOn = GIANGVIEN.MaGV;

select * from TINCHI
where MaGVDay is  null or MaGVOn is null;