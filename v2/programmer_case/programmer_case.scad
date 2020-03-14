//linear_extrude(height = fanwidth, center = true, convexity = 10)
  // import (file = "pcb_boarder.dxf");
  
pcb_width = 90.81;
pcb_height = 70.12;

base_height = 26;
base_wall_thickness = 10;

usb_module_support_length = 25.1;
card_height_position = 5;
card_depth = 3; 
card_finger_grabber_radius = 5;
cable_port_radius = 15;



module frame() {
    union() {
        translate([0,card_height_from_wall,0])
            square([usb_module_support_length,usb_module_support_length+base_wall_thickness]);
        difference() {
            square([pcb_width,pcb_height]);  
            translate([base_wall_thickness,base_wall_thickness,0])
                square([pcb_width-base_wall_thickness*2, pcb_height - base_wall_thickness*2]);
        };            
    }
}

module case() {
    difference() {
        linear_extrude(height = base_height) {
            frame();
        }
                
        translate([0, card_height_position, base_height - card_depth])
            linear_extrude(height = card_depth)
                import (file = "pcb_boarder.dxf");
        
        translate([0, 47.5, base_height])
            rotate([0,90,0])
                cylinder(base_wall_thickness, card_finger_grabber_radius, card_finger_grabber_radius);
        
        translate([50,0,0])
            rotate([-90,0,0])
                cylinder(base_wall_thickness, cable_port_radius, cable_port_radius);
    }
}

case ();

