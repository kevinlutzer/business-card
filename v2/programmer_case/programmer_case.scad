base_width = 90;
base_height = 70;
base_depth = 13;
base_wall_thickness = 10;

pcb_depth = 1.2;
pcb_height = 51;
pcb_length = 70;
pcb_length_offset = 5.34;

usb_module_support_length = 25.1;
card_height_position = 5;
card_depth = 3; 
card_finger_grabber_radius = 5;
cable_port_radius = 10;

plunger_offset = 30;
plunger_height = 15;
plunger_length = 25;


module pcb() {
    linear_extrude(height = pcb_depth) {
        square([pcb_length, pcb_height]);
    }
}

module frame() {
    union() {
        square([usb_module_support_length,usb_module_support_length+base_wall_thickness]);
        difference() {
            square([base_width,base_height]);  
            translate([base_wall_thickness,base_wall_thickness,0])
                square([base_width-base_wall_thickness*2, base_height - base_wall_thickness*2]);
        };            
    }
}

module case() {
    difference() {
        linear_extrude(height = base_depth) {
            union() {
               frame();
               translate([plunger_offset, base_height, 0])
                square([plunger_length, plunger_height]);
            }
        }
                
        translate([0, card_height_position, base_depth - card_depth])
            linear_extrude(height = card_depth)
                import (file = "pcb_boarder.dxf");
        
        translate([0, 47.5, base_depth])
            rotate([0,90,0])
                cylinder(base_wall_thickness, card_finger_grabber_radius, card_finger_grabber_radius);
        
        translate([50,0,0])
            rotate([-90,0,0])
                cylinder(base_wall_thickness, cable_port_radius, cable_port_radius);
        
        translate([pcb_length_offset, card_height_position, 0])
            pcb();
    }
}

case ();

