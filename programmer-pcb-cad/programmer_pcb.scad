module frame() {
    linear_extrude(height = 13)
    union() {
        square([10, 100]);
        translate([90,0,0]) square([10, 100]);
        translate([0,65,0]) square([100, 10]);
        translate([-20,38,0]) square([25,25]);
    }       

}

module business_card() {
    translate([5, 23.8026, 11])
        linear_extrude(height = 3)
            translate([ - 0.02 * 89 / 2 , - 0.02 * 51 / 2, 0])
                scale([1.02, 1.02, 1]) 
                    import("./pcb_boarder.dxf"); // 89 long and 51 cm wide// 89 long and 51 cm wide
}

module screw_cutout_grid(x, y, h = 4, r = 1.5) {
    cylinder(h = h, r = r, $fn=100);
    translate([x, y, 0]) cylinder(h = h, r = r, $fn=100);
    translate([0, y, 0]) cylinder(h = h, r = r, $fn=100);
    translate([x, 0, 0]) cylinder(h = h, r = r, $fn=100);
}

module main() {
    difference() {
        frame(); 
        business_card();
        translate([25, 90, 0]) { linear_extrude(height = 11) { square([60,30]); } }
        translate([5, 5, 0]) screw_cutout_grid(90,90);
        translate([-16, 42.5, 9]) screw_cutout_grid(13.5, 16);
    }
}

//frame();
//business_card();
    main();
//frame();