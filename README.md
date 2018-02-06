# CoverageJSON-Response-Handler-for-OPeNDAP

WORK IN PROGRESS README

## Development will be taking place in the following repositories:
- https://github.com/RiverHendriksen/hyrax
- https://github.com/RiverHendriksen/olfs
- https://github.com/RiverHendriksen/bes

## Problem Statement

One way that satellite data is currently handled by NASA is through OPeNDAP, Open-source Project for a Network Data Access Protocol. OPeNDAP is a data transport protocol that supplies its users a way to provide and request data across the web. One of the main functions of the protocol is the ability to pull data in multiple different formats including ASCII, netCDF3, netCDF4, binary (DAP2), and several other object serializations. OPeNDAP does not currently have a response handler in place to serve data in the CoverageJSON data format, which is a JavaScript Object Notation (JSON) data format for describing coverages. CoverageJSON would be a very useful format to have available from OPeNDAP due to it encoding data values based upon a spatial temporal domain similar to how satellite data is collected from NASA's satellites. The integration of the CoverageJSON format into OPeNDAP would help support the creation of coverage data driven web applications by NASA JPL(Jet Propulsion Lab) and any other users of OPeNDAP.

## Proposed Solution

The proposed solution would be to develop a CoverageJSON response handler that can be integrated into the OPeNDAP open-source code base.
Initially our team would need to develop an understanding of the following areas:
 - NASA JPL's currently supported scientific data formats in OPeNDAP and how it will be represented in CoverageJSON.
 - The OPeNDAP code base and how response handling is done within OPeNDAP.
 - The CoverageJSON data format and how it can be integrated into OPeNDAP.
 
Gathering the required knowledge on these systems will require documentation and contact from NASA JPL and the OPeNDAP team/ community. We will also need to get information on the documentation and testing the OPeNDAP team will expect for the proposed response handler to be integrated into the OPeNDAP project. Once our group has a good understanding of how this protocol and data format can fit together we need to plan out the actual implementation of the CoverageJSON response handler. The response handler will be written in C++ and will conform to the current OPeNDAP response handlers. The logic for the data conversion into the CoverageJSON format will be based off of pycovjson, an existing library for making CovJSON files from scientific data formats. The entirety of the project will be written using GitHub source control and will naturally be open source since it will be pulled into the OPeNDAP project. The documentation and testing done for the code will be up to the specifications we gather from the OPeNDAP team and NASA JPL. The implementation will also be tested to ensure it is fully compatible with the existing data that NASA JPL has in OPeNDAP. The deliverables expected for this implementation will be as follows:
 - A project website that is served on GitHub that hosts all of the code and documentation.
 - The CoverageJSON response handler code, ready to be integrated or in the process of being integrated into OPeNDAP.
 - Documentation and testing to the level needed for the code to be integrated into OPeNDAP.
 - A poster outlining the project to the American Geophysical Union.
 
The project is expected to be complete in early 2018, and will be presented at Oregon State University in the engineering expo in May of 2018 with a poster outlining the project.
